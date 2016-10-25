// MiddleEar.h

#ifndef MIDDLEEAR_H
#define MIDDLEEAR_H 

#include "Parameters.h"
#include <complex>
#include <string>

using std::string;
using std::complex;

typedef complex<float>* DataArray;

// Contains declarations for MiddleEar Class

class MiddleEar {

public:
	
	// constructors
	MiddleEar();
	MiddleEar(int freq_range);
	MiddleEar(int freq_range, int pressure_range);

	// destuctor
	~MiddleEar();

	// assessor - mutator functions
	void setAge(int age_of_person);
	void setName(const string& storename) { storeto = storename; };
	void setDiameter(float diameter=1.0);
	void setLength(float length = 1.0);
	
	int  getAge() const;
	float getDiameter() const;
	float getLength() const;
	int getSpeedofSound() const;
	complex<float> getData(int ind) const;
	
	// store function
	void storeData();

	// general purpose
	int square(int x);
	float square(float x);
	double square(double x);

	complex<float> impedanceToAdmittance(const complex<float>& impedance);

protected:
	// also available in child classes
	int index;
	ParamEarCanal PEC;
	ParamGeneral PG;
	string storeto;

	// supporting functions
	float angularFreq(int freq);	// angular frequency

private:
	int age;
	ParamKringlebotn PK;
	DataArray Data;
			
	// functions acting on data
	void kringlebotn();
	
};




#endif