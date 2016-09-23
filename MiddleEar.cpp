
#include "MiddleEar.h"
#include <complex>
#include <cmath>


typedef float* Data;

// define functions and constructors class MiddleEar

// class constructors
MiddleEar::MiddleEar(){
	// default constructor

	/* for now do nothing */
}

MiddleEar::MiddleEar(int freq_range) {

	/*
	insert dynamic allocated array?
	*/

	/*------------------------------------------------ 
	needs to be a 3D array the size of freq_range
	times pressure times (normalized between 0 and 1?)
	------------------------------------------------*/
}



// functions acting on data
void MiddleEar::kringlebotn() {

	// Z1a
	
	// create complex variables
	std::complex<double> Z1;
	std::complex<double> Z2;

	/*
	// part 1
	double Xeq_1 = (w*La) - (1 / (w*Ca));
	double Req_1 = Ra;

	// part 2
	double Xeq_2 = -1 / (w*Ct);
	double Req_2 = 0;

	// total equavalent impedance
	Z1.imag(Xeq_1);
	Z1.real(Req_1);
	Z2.imag(Xeq_2);
	Z2.real(Req_2);

	complex<double> Z = Z1*Z2 / (Z1 + Z2);
	*/

}


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

	return PEC.LengthEar;
}

int MiddleEar::getSpeedofLight() {

	return PG.c;
}