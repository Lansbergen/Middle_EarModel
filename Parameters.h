#ifndef PARAMETERS_H
#define PARAMETERS_H 


// Paramaters.h

/*----------------------------------------------------
Includes all parameters for the MiddleEar class
-----------------------------------------------------*/

// general
struct ParamGeneral {
	const int c = 35188;            // cm/sec @ 25 degC - speed of sound
	const float pi = 3.1415926536f; // pi to 10th decimal
	const double rho = 1.2040e-3;   // g/cm ^ 3 @  0daPa   @ 25 degC - density air
};



// ear canal dimensions
struct ParamEarCanal {

	ParamGeneral PG;

	float LengthEar; // length ear canal dimensions
	float DiamEar; // diameter ear canal dimensions
	double Vec = (PG.pi * (DiamEar*DiamEar)  * LengthEar) / 8;   // volume of tappered ear - canal
};

// (static) middle ear parameters
struct ParamKringlebotn {

	// block Z1a
	/*
	const double La;  // = Pk.rho*change.mec_v; // coupled to volume
	const doubleCtot = (change.mec_v / (Pk.rho.*(Pk.c) ^ 2)).*change.pat_fact;  // total compliance of the ear - canal cavities
	const doublePk.Ca = 0.925*Ctot;   // compliance / factor .925 for Ca
	const doublePk.Ct = 0.075*Ctot;   // compliance / factor .075 for Ct
	const doublePk.Ra = change.mec_R; // resistance
	*/
	// alternatively -> fixed values
	const float La = 1e-3f;		// inertance
	const float Ca = 3.9e-6f;	// compliance
	const float Ct = 0.4e-6f;	// compliance
	const int Ra = 60;			// resistance

	// block Z1b
	const float Ld = 7.5e-3f;   // inertance
	const float Ls = 66e-3f;    // inertance
	const float Cs = 0.3e-6f;   // compliance
	const float Cr = 1.3e-6f;   // compliance
	const int Rs = 20;		    // resistance
	const int Rr = 120;			// resistance

	// block Z2
	const float Cm = 0.38e-6f;	// compliance
	const int Rm = 120;			// resistance

	// block Z3
	const float Lo = 22e-3f;	// inertance
	const int Ro = 20;			// resistance

	// block Z4
	const float Ci = 0.3e-6f;	// compliance
	const int Ri = 6000;		// resistance

	// block Z5
	const float Lc = 46e-3f;	// inertance
	const float Cc = 0.56e-6f;	// compliance
	const int Rc = 330;			// resistance

};



#endif
