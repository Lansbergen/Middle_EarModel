// AdultModel.h

#ifndef ADULTMODEL_H
#define ADULTMODEL_H 

#include "MiddleEar.h"

typedef float* PressureDataArray;

class AdultModel : public MiddleEar
{

public:
	
	enum format { IMPEDANCE, ADMITTANCE, PRESSURE, DERIVATIVE };

	// constructors
	AdultModel();
	AdultModel(int freq_range);
	AdultModel(int freq_range,float diameter, float length);
	AdultModel(int freq_range, int pressure_range);
	AdultModel(int freq_range,int pressure_range, float diameter, float length);
	// destructor
	~AdultModel();

	void storeData(format output = IMPEDANCE);
	void storeData(DataArray data, int size);

	// functions acting on data (public)
	void deriv(int DerOrder);

private:
	// functions acting on data (private)
	void keefe();
	void pressure();

	// 2D data Arrays
	DataArray DataKeefeImp;
	DataArray DataKeefeAdm;
	DataArray Der;

	// 3D data Array
	PressureDataArray* test;
	PressureDataArray* Real;
	PressureDataArray* Imag;
	PressureDataArray* Yabs;

	int PressureRange;
};










#endif