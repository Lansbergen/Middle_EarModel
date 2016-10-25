// AdultModel.cpp

#include <complex>
#include <iostream>
#include <fstream>
#include <string>
#include "MiddleEar.h"
#include "AdultModel.h"

using std::string;
using std::cout;




// define functions and constructors class AdultModel

/*
- Public -
*/

// class constructors
AdultModel::AdultModel():MiddleEar() {
	
	cout << "\n Using Normal Adult Combined Middle-ear & Ear-Canal model - object \n";
	// create empty object for now
}

AdultModel::AdultModel(int freq_range) : MiddleEar(freq_range) {
	
	cout << "\n Using Normal Adult Combined Middle-ear & Ear-Canal model - object \n";
	cout << "\n Using default dimensions for an adult ear-canal: \n";
	cout << "\n Diameter = 1.4 cm, Length = 2.5 cm \n";
	// define new dynamic complex array
	DataKeefeImp = new complex<float>[freq_range];
	DataKeefeAdm = new complex<float>[freq_range];

	// set ear-canal values to default (centimeters)
	setDiameter(1.4);
	setLength(2.5);
	
	// apply combined middle-ear and ear-canal model (Adult ver)
	keefe();
}

AdultModel::AdultModel(int freq_range, float diameter, float length) : MiddleEar(freq_range) {

	cout << "\n Using Normal Adult Combined Middle-ear & Ear-Canal model - object \n";

	// define new dynamic complex array
	DataKeefeImp = new complex<float>[freq_range];
	DataKeefeAdm = new complex<float>[freq_range];
	
	setDiameter(diameter);
	setLength(length);

	// apply combined middle-ear and ear-canal model (Adult ver)
	keefe();

}

AdultModel::AdultModel(int freq_range, int pressure_range) : MiddleEar(freq_range) {

	cout << "\n Using Normal Adult Combined Middle-ear & Ear-Canal model - object \n";
	cout << "\n Using default dimensions for an adult ear-canal: \n";
	cout << "\n Diameter = 1.4 cm, Length = 2.5 cm \n";
	cout << "\n *** With added Pressure relation \n";

	PressureRange = pressure_range * 2;

	if (PressureRange > 600) {
		cout << "\nError: Pressure Range exceeds maximum, max -> +/- 300 daPa \n";
		exit(EXIT_FAILURE);
	}

	// define new dynamic complex array
	DataKeefeImp = new complex<float>[freq_range];
	DataKeefeAdm = new complex<float>[freq_range];

	// set ear-canal values to default (centimeters)
	setDiameter(1.4);
	setLength(2.5);
		
	// apply combined middle-ear and ear-canal model (Adult ver)
	keefe();

	// apply pressure relation based on Vanhuyse framework
	pressure();

}

AdultModel::AdultModel(int freq_range, int pressure_range, float diameter, float length) : MiddleEar(freq_range) {

	cout << "\n Using Normal Adult Combined Middle-ear & Ear-Canal model - object";
	cout << "\n *** With added Pressure relation \n";

	PressureRange = pressure_range*2;

	if (PressureRange > 600) {
		cout << "\nError: Pressure Range exceeds maximum, max -> +/- 300 daPa \n";
		exit(EXIT_FAILURE);
	}

	// define new dynamic complex array
	DataKeefeImp = new complex<float>[freq_range];
	DataKeefeAdm = new complex<float>[freq_range];

	// set ear-canal variables
	setDiameter(diameter);
	setLength(length);

	// apply combined middle-ear and ear-canal model (Adult ver)
	keefe();

	// apply pressure relation based on Vanhuyse framework
	pressure();
	
			
}

// destructor
AdultModel::~AdultModel() {
	/*
	delete [] DataKeefeImp;
	delete [] DataKeefeAdm;
	delete [] Real;
	delete [] Imag;
	*/
}

void AdultModel::storeData(format output) {
		
	std::ofstream file_out;

	// write to output.txt
	if (!storeto.empty()) {
		file_out.open(storeto);
		cout << "\n write data to " << storeto << "\n";
	}
	else {
		file_out.open("output.txt");
		cout << "\n write data to output.txt \n";
	}

	switch (output)
	{
	case AdultModel::IMPEDANCE:
		
		for (int i = 1; i <= index; i++) {
			file_out << DataKeefeImp[i] << std::endl;
		}

		break;
	case AdultModel::ADMITTANCE:
		
		for (int i = 1; i <= index; i++) {
			file_out << DataKeefeAdm[i] << std::endl;
		}
		
		break;
	case AdultModel::PRESSURE:

		for (int i = 0; i < PressureRange; i++) {	
			
			if(i > 0) file_out << std::endl;
			
			for (int j = 1; j <= index; j++) {
				file_out << Yabs[i][j] << ",";
			}
		}
		
		break;
	case AdultModel::DERIVATIVE:

		for (int i = 0; i <= index-2; i++) {
			file_out << Der[i] << std::endl;
		}

		break;
	default:
		cout << "\n\n DEFAULT \n\n";
		break;
	}

	

	file_out.close();

	cout << "\n Adult - combined model data saved to file \n";

}

/*
- Private -
*/


// implementation model Keefe
void AdultModel::keefe() {
		
	for (int i = 1; i <= index; i++) {

		/*
		Define Kringlebotn Resistance and Reactance (R+jX) elements
		into Compliance and inertance compontents for compatibility
		with merged Kringlebotn/Keefe model 
		*/

		// get angular frequency
		float w = angularFreq(i);

		// inertance (L) and compliance (C) component Kringlebotn middle-ear model
		float Lm = getData(i).imag() / w;
		float Cm = -1 / (w * getData(i).imag());

		/*
		Keefe ear-canal (shunt) model: ear-canal model implementation
		*/
		
		// inertance (L) and compliance (C) component ear-canal (shunt) Keefe
		//float Lv = PG.rho*PEC.Vec*PEC.LengthEar;
		
		// volume of tappered ear - canal
		double Vec = (PG.pi * square(PEC.DiamEar)  * PEC.LengthEar) / 8;

		float Lv = PG.rho*square(Vec);
		float Cv = 1 / (w*(((PG.rho*PG.c) / square(PG.pi*(PEC.DiamEar / 2) )) *(2 / (w / PG.c)*PEC.LengthEar)));
			

		// ear-canal-model (shunt) impedance of the ear - canal
		// float Xcv = abs(-1 / (w*Cv));	// Reactance form compliance component ear-canal
		// float Xlv = Lv*w;				// Reactance from Inductance component ear-canal
		
		// float Rv = 0;					// Resistance ear-canal, neglect setting it to 0
		// float Xv = Xlv - Xcv;			// Overall reactance ear-canal
		// complex<float> Zv(Rv, Xv);		// Impedance ear - canal

		/*
		Keefe wall-ear-canal is not implemented in the AdultModel class: is not active 
		and effect can be dismissed. See also model specifications by Keefe et al. (1993)
		*/

		/* Resistance and reactance components combined ear-canal and middle-ear */
		float totC = Cm + Cv;			// combined compliance ear-canal and middle-ear
		float totL = Lm + Lv;			// combined inertance ear-canal and middle-ear
		float totR = 0;					// combined resistance ear-canal and middle-ear
		float totXc = -1 / (w * totC);
		float totXl = totL * w;
		
		/* combined impedances ear-canal and middle-ear */
		DataKeefeImp[i].imag(totXl - totXc+150);		// combined reactance (including inductance)
		//DataKeefe[i].imag(totXc);						// combined reactance, neglect inertance component(See Keefe)
		DataKeefeImp[i].real(getData(i).real() + totR);	// combined resistance
		
		DataKeefeAdm[i] = impedanceToAdmittance(DataKeefeImp[i]);
		
	}
	
	/*
			case 1 % neglect compliant wall effect
			ke.Zk = complex(totR, totX);                  % Impedance combined imp
			ke.Xk = imag(ke.Zk) + Pk.addC;    			 % Reactance from total model
			switch Pk.fixR_onoff
				case 0 % off
				ke.Rk = real(ke.Zk);		    			 % Resistance from total model
				case 1 % on
				tijd = ones(1, length(w));
		ke.Rk = tijd.*Pk.fixR; % Resistance fixed parameter parameter
			end
			end

								 % admittance complete model

	*/
	
	
	
};


void AdultModel::pressure() {

	cout << "\n\n Pressure Range between -" << PressureRange / 2 << " daPa and " << PressureRange / 2 << " daPa \n";
	
	Real = new PressureDataArray[PressureRange];
	Imag = new PressureDataArray[PressureRange];
	Yabs = new PressureDataArray[PressureRange];

	int i,j;
	
	for (i = 0; i < PressureRange; i++) {
		Real[i] = new float[index];
		Imag[i] = new float[index];
		Yabs[i] = new float[index];
	}

	int StartPressure = (PressureRange / 2) - PressureRange;
	
	
	for (i = 0; i < PressureRange; i++) {
		
		int NextPressure = StartPressure + i;

		for (j = 1; j <= index; j++) {
			// add Vanhuyse framework to model predictions
			Real[i][j] = DataKeefeImp[j].real() + ( 300.f * exp(-(NextPressure - 100.f) / 600.f) - 354.4f);
			Imag[i][j] = DataKeefeImp[j].imag() + (-square(NextPressure / 2.5f));
		
			complex<float> admittance = impedanceToAdmittance(complex<float>(Real[i][j], Imag[i][j]));
			Yabs[i][j] = abs(admittance);

			//cout << Yabs[i][j] << "\n";
		}
	}
		
}


void AdultModel::deriv(int DerOrder) {

	Der = new complex<float>[index-1];

	if (DerOrder == 1) {
		for (int i = 0; i <= index-2; i++) {
			Der[i].imag(DataKeefeImp[i + 1].imag() - DataKeefeImp[i + 2].imag());
			Der[i].real(DataKeefeImp[i + 1].real() - DataKeefeImp[i + 2].real());
		}
	}
	else {
		cout << "\nnothing yet\n";
	}

}