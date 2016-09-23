// Paramaters.h

/*----------------------------------------------------
Includes all parameters for the MiddleEar class
-----------------------------------------------------*/

// general
struct ParamGeneral {
	const int c = 35188;            // cm/sec @ 25 degC - speed of sound
	const double pi = 3.1415926536; // pi to 10th decimal
	const double rho = 1.2040e-3;   // g/cm ^ 3 @  0daPa   @ 25 degC - density air
};



// ear canal dimensions
struct ParamEarCanal {

	ParamGeneral PG;

	double LengthEar; // length ear canal dimensions
	double DiamEar; // diameter ear canal dimensions
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
	// alternatively
	const double La = 1e-3;		// inertance
	const double Ca = 3.9e-6;	// compliance
	const double Ct = 0.4e-6;	// compliance
	const int Ra = 60;			// resistance

								// block Z1b
	const double Ld = 7.5e-3;     // inertance
	const double Ls = 66e-3;      // inertance
	const double Cs = 0.3e-6;     // compliance
	const double Cr = 1.3e-6;     // compliance
	const int Rs = 20;         // resistance
	const int Rr = 120;        // resistance



};