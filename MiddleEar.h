// MiddleEar.h

#ifndef MIDDLEEAR_H
#define MIDDLEEAR_H 

#include "Parameters.h"


// Contains declarations for MiddleEar Class

class MiddleEar {

public:
	
	// constructors
	MiddleEar();
	MiddleEar(int freq_range);
	
	// assessor - mutator functions
	void setAge(int age_of_person);
	int getAge();
	int getSpeedofLight();

	// functions acting on data
	void kringlebotn();
	
private:
	int age;
	ParamGeneral PG;

};




#endif