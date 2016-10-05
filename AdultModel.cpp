// AdultModel.cpp

#include <complex>
#include <iostream>
#include "MiddleEar.h"
#include "AdultModel.h"

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
	
	// create empty object for now
}


/*
- Private -
*/

// implementation combined model 
void AdultModel::combinedModel() {

	for (int i = 1; i <= index; i++) {

		/*
		Define Kringlebotn Reactance and Susceptance (R+jX) elements
		into Compliance and inertance compontents for compatibility
		with combined middle ear model
		*/

		cout << getData(i) << std::endl;

				
		Lm = kr.Xeq. / w;					   	      % inertance middle - ear
		Cm = -1. / (w.*kr.Xeq);				   	  % compliance middle - ear


	}

}

// implementation model Keefe
void AdultModel::keefe() {
		
	double Lv = PG.rho*PEC.Vec;   // inertance ear-canal (shunt)
	//Cv = 1. / (w.*(((Pk.rho*Pk.c) . / (pi*(Pk.d / 2) ^ 2)) .*(2. / (w. / Pk.c).*Pk.l)));
		/*
				
			% wall admittance(step1 / step2)
			Bm = -kr.Xeq . / (kr.Req. ^ 2 + kr.Xeq. ^ 2);  % susceptance middle - ear
			Cm_s = Bm . / w;                           % compliance from susceptance middle - ear
			Cw = Pk.fCC.*Cm_s;                		  % compliance of ear - canal wall
			step1 = Cw.*w.*(1 - (w. / Pk.Ww). ^ 2).*1i + (Pk.Ww.*Cw). / Pk.Qw; % (step 1)
			step2 = ((1 - (w. / Pk.Ww). ^ 2). ^ 2) + (w. / (Pk.Ww.*Pk.Qw)). ^ 2; % (step 2)

			% ear - canal model->shunt impedance of the ear - canal
			Xcv = abs(-1. / (w.*Cv));		     % Compliance ear - canal
			Rv = 0;                    		 % Resistance ear - canal, neglect setting it to 0
			Xlv = Lv.*w;             		     % Inductance ear - canal
			Xv = Xlv - Xcv;          			 % Reactance ear - canal

			Zv = complex(Rv, Xv);				 % impedance ear - canal

			% combined impedances ear - canal and middle - ear
			totC = Cm + Cv;       		 	 % combined compliance ear - canal and middle - ear
			totL = Lm + Lv;		     		 % combined inertance ear - canal and middle - ear
			totXc = 1. / (w.*totC);
		totXl = totL.*w;

		% totX = ke.totXl - ke.totXc;	 % combined reactance
			totX = -totXc;                   % combined reactance, neglect inertance component(See Keefe)
			totR = kr.Req + Rv;			     % combined resistance

			% wall effect
			Yw = step1. / step2;               % wall admittance
			Gw = real(Yw);	                 % wall conductance
			Bw = imag(Yw);  	             % wall susceptance
			Rw = Gw . / (Gw. ^ 2 + Bw. ^ 2);  	 % wall resistance
			Xw = -Bw . / (Gw. ^ 2 + Bw. ^ 2); 	 % wall reactance
			Zw = complex(Rw, Xw);             % wall impedance

			% total impedance ear - canal and
			switch Pk.onoff
				case 0 % with compliant wall effect
				Z = complex(totR, totX);
		ke.Zk = Z.*Zw . / (Z + Zw);  			     % Impedance wall - effect and impedance combined in parallel
			ke.Xk = imag(ke.Zk) + Pk.addC; 				 % Reactance from total model
			switch Pk.fixR_onoff
				case 0 % off
				ke.Rk = real(ke.Zk);    					 % Resistance from total model
				case 1 % on
				tijd = ones(1, length(w));
		ke.Rk = tijd.*Pk.fixR; % Resistance fixed parameter parameter
			end
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

			ke.Gk = ke.Rk . / (ke.Xk. ^ 2 + ke.Rk. ^ 2);				 % conductance complete model
			ke.Bk = -ke.Xk . / (ke.Xk. ^ 2 + ke.Rk. ^ 2);			 % susceptance complete model
			ke.Yk = complex(ke.Gk, ke.Bk);						 % admittance complete model

	*/
	
	
	
};