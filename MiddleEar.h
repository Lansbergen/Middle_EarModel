// MiddleEar.h

#ifndef MIDDLEEAR_H
#define MIDDLEEAR_H 

#include "Parameters.h"
#include <complex>

typedef std::complex<float>* DataArray;

// Contains declarations for MiddleEar Class

class MiddleEar {

public:
	
	// constructors
	MiddleEar();
	MiddleEar(int freq_range);
	MiddleEar(int freq_range, int pressure_range);

	// assessor - mutator functions
	void setAge(int age_of_person);
	int  getAge() const;
	
	void setDiameter(float diameter=1.0);
	void setLength(float length = 1.0);
	float getDiameter() const;
	float getLength() const;
	
	int getSpeedofSound() const;

	
	
	// store function
	void storeData();


private:
	int age;
	int index;
	ParamGeneral PG;
	ParamKringlebotn PK;
	ParamEarCanal PEC;
	DataArray Data;

	// supporting functions
	float angularFreq(int freq);	// angular frequency

	// functions acting on data
	void kringlebotn();
	void keefe();
};




#endif