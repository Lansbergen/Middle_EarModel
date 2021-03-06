
#include "MiddleEar.h"
#include <complex>
//#include <cmath>
#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::cout;
using std::complex;

// define functions and constructors class MiddleEar

// class constructors
MiddleEar::MiddleEar(){
	// default constructor

	/* for now do nothing */

	Data = NULL;

}

MiddleEar::MiddleEar(int freq_range) {
	
	if (freq_range > 2500) {
		cout << "Error: Frequency range exceeds 2500 Hz.";
		exit(EXIT_FAILURE);
	};

	cout << "\n Using Middle-ear base class - object \n";

	/*------------------------------------------------
	needs to be a 1D array the size of freq_range
	(thus index is 1 serves as 2nd dimension)
	------------------------------------------------*/

	Data = new complex<float>[freq_range];

	index = freq_range;

	kringlebotn();
		
}

MiddleEar::MiddleEar(int freq_range, int pressure_range) {

	/*
	insert dynamic allocated array?
	*/

	/*------------------------------------------------
	needs to be a 2D array the size of freq_range
	times pressure times 
	(thus index is 1 serves as 3th dimension)
	------------------------------------------------*/
}

// destructor
MiddleEar::~MiddleEar() {

	//delete[] Data;

}

/*
- Public functions -
*/

// accessor and mutation functions
void MiddleEar::setAge(int age_of_person) {
	age = age_of_person;
}

void MiddleEar::setDiameter(float diameter) {

	PEC.DiamEar = diameter;
}

void MiddleEar::setLength(float length) {

	PEC.LengthEar = length;
}

int MiddleEar::getAge() const {

	return this->age;
}

float  MiddleEar::getDiameter() const {

	return PEC.DiamEar;
}

float  MiddleEar::getLength() const {

	//return PEC.LengthEar;
	return PK.Ca;
}

int MiddleEar::getSpeedofSound() const {

	return PG.c;
}

complex<float> MiddleEar::getData(int ind) const {

	if (ind > index || ind == 0) {

		cout << "\ngetData: An Error Occurred, called index is greater then frequency index or is 0 \n";

		// insert error if ind exceeds max frequency range (index) or if 0
		exit(EXIT_FAILURE);
	}
	else {
		return Data[ind];
	}
}

void MiddleEar::storeData() {

	std::ofstream file_out;

	// write to output.txt
	if(!storeto.empty()){
	file_out.open(storeto);
	cout << "\n write data to " << storeto << "\n";
	}
	else {
	file_out.open("output.txt");
	cout << "\n write data to output.txt \n";
	}
	
	for (int i = 1; i <= index; i++) {
		file_out << Data[i] << std::endl;
	}
		
	file_out.close();

	cout << "\n Kringlebotn model data saved to file \n";
}

int MiddleEar::square(int x) {

	return x*x;
}

float MiddleEar::square(float x) {

	return x*x;
}

double MiddleEar::square(double x) {

	return x*x;
}

complex<float> MiddleEar::impedanceToAdmittance(const complex<float>& impedance) {

	/*
	Converts Impedance (Z) to Admittance (Y) by calculating individual conductance
	and susceptance components, which are the reciprocal of resistance (R) and 
	reactance (X) components
	*/

	float X = impedance.imag();
	float R = impedance.real();

	float G = R / (square(X) + square(R));	// Conductance
	float B = -X / (square(X) + square(R)); // Susceptance
	
	return complex<float>(G,B);

}

/* 
- Private functions - 
*/

// supporting functions
float MiddleEar::angularFreq(int freq) {
	
	float w = 2 * PG.pi * freq;

	return w;
};

// functions acting on data
void MiddleEar::kringlebotn() {

	// fill Data array (Kringlebotn) middle-ear model
	for (int i = 1; i <= index; i++) {
		
		float w = angularFreq(i);

		/* Block Z1a */

		// part 1
		float Xeq_1a_1 = (w*PK.La) - (1 / (w*PK.Ca));
		float Req_1a_1 = PK.Ra;

		// part 2
		float Xeq_1a_2 = -1 / (w*PK.Ct);
		float Req_2a_2 = 0;
		
		// total equavalent impedance Z1a
		complex<float> Z1a_1, Z1a_2, Z1a;
		Z1a_1.imag(Xeq_1a_1);
		Z1a_1.real(Req_1a_1);
		Z1a_2.imag(Xeq_1a_2);
		Z1a_2.real(Req_2a_2);
		Z1a = Z1a_1*Z1a_2 / (Z1a_1 + Z1a_2);

		/* Block Z1b */
				
		// part 1
		float Xeq_1b_1 = (w*PK.Ls) - (1 / (w*PK.Cs));
		float Req_1b_1 = PK.Rs;

		// part 2
		float Xeq_1b_2 = -1 / (w*PK.Cr);
		float Req_1b_2 = PK.Rr;

		// total equavalent impedance
		complex<float> Z1b_1, Z1b_2, Z1b_12;
		Z1b_1.imag(Xeq_1b_1);
		Z1b_1.real(Req_1b_1);
		Z1b_2.imag(Xeq_1b_2);
		Z1b_2.real(Req_1b_2);
		Z1b_12 = Z1b_1*Z1b_2 / (Z1b_1 + Z1b_2);
		
		// part 3
		float Xtot = Z1b_12.imag() + w*PK.Ld;
		
		// total equavalent impedance
		complex<float> Z1b;
		Z1b.real(Z1b_12.real());
		Z1b.imag(Xtot);

		
		/* Block Z2 */

		// part 1
		float Xeq_2 = -(1 / (w*PK.Cm));
		float Req_2 = PK.Rm;
		// total impedance Z2
		complex<float> Z2;
		Z2.real(Req_2);
		Z2.imag(Xeq_2);

		
		/* Block Z3 */
		
		// part 1
		float Xeq_3 = w*PK.Lo;
		float Req_3 = PK.Ro;
		// total impedance Z3
		complex<float> Z3;
		Z3.real(Req_3);
		Z3.imag(Xeq_3);

		
		/* Block Z4 */

		// part 1
		float Xeq_4 = -(1 / (w*PK.Ci));
		float Req_4 = PK.Ri;
		// total impedance Z4
		complex<float> Z4;
		Z4.real(Req_4);
		Z4.imag(Xeq_4);


		/* Block Z5 */

		// part 1
		float Xeq_5 = w*PK.Lc - (1 / (w*PK.Cc));
		float Req_5 = PK.Rc;
		// total impedance Z5
		complex<float> Z5;
		Z5.real(Req_5);
		Z5.imag(Xeq_5);


		/* Total impedance Z1a to Z5 */

		// step 1
		complex<float> Zeq_step1 = Z4*Z5 / (Z4 + Z5);
		// step 2
		complex<float> Zeq_step2 = Z3 + Zeq_step1;
		// step 3
		complex<float> Zeq_step3 = Z2*Zeq_step2 / (Z2 + Zeq_step2);
		// step 4
		Data[i] = Z1a + Z1b + Zeq_step3;

		
		// dump data on screen for debugging purpose
		//std::cout << Data[i] << "\n";
		
		

	};
		

}

