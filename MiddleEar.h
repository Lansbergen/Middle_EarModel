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
	int  getAge();
	
	void setDiameter(float diameter=1.0);
	void setLength(float length = 1.0);
	float getDiameter();
	float getLength();
	
	int getSpeedofLight();

	// functions acting on data
	void kringlebotn();
	

private:
	int age;
	ParamGeneral PG;
	ParamKringlebotn PK;
	ParamEarCanal PEC;

};




#endif