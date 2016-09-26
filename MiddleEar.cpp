
#include "MiddleEar.h"
#include <complex>
#include <cmath>
#include <iostream>


// define functions and constructors class MiddleEar

// class constructors
MiddleEar::MiddleEar(){
	// default constructor

	/* for now do nothing */

	Data = NULL;

}

MiddleEar::MiddleEar(int freq_range) {
	
	if (freq_range > 2500) {
		std::cout << "Error: Frequency range exceeds 2500 Hz.";
		exit(1);
	};

	/*------------------------------------------------
	needs to be a 1D array the size of freq_range
	(thus index is 1 serves as 2nd dimension)
	------------------------------------------------*/

	Data = new std::complex<float>[freq_range];

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

/*
- Public functions -
*/

// accessor and mutation functions
void MiddleEar::setAge(int age_of_person) {
	age = age_of_person;
}

int MiddleEar::getAge() {

	return this->age;
}

void MiddleEar::setDiameter(float diameter) {

	PEC.DiamEar = diameter;
}

void MiddleEar::setLength(float length) {

	PEC.LengthEar = length;
}

float  MiddleEar::getDiameter() {

	return PEC.DiamEar;
}

float  MiddleEar::getLength() {

	//return PEC.LengthEar;
	return PK.Ca;
}

int MiddleEar::getSpeedofSound() {

	return PG.c;
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

	// Z1a
	// create complex variables
	DataArray Z1a_1, Z1a_2;
	Z1a_1 = new std::complex<float>[index];
	Z1a_2 = new std::complex<float>[index];


	for (int i = 1; i < index; i++) {
		
		float w = angularFreq(i);

		// part 1
		double Xeq_1 = (w*PK.La) - (1 / (w*PK.Ca));
		double Req_1 = PK.Ra;

		// part 2
		double Xeq_2 = -1 / (w*PK.Ct);
		double Req_2 = 0;
		
		// total equavalent impedance Z1a
		Z1a_1[i].imag(Xeq_1);
		Z1a_1[i].real(Req_1);
		Z1a_2[i].imag(Xeq_2);
		Z1a_2[i].real(Req_2);
		
		Data[i].real(i);
		Data[i].imag(i + 1);

		Data[i] = Z1a_1[i]*Z1a_2[i] / (Z1a_1[i] + Z1a_2[i]);

		std::cout << Data[i] << "\n";
	};





}
