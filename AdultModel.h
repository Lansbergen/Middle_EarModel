// AdultModel.h

#ifndef ADULTMODEL_H
#define ADULTMODEL_H 

#include "MiddleEar.h"


class AdultModel : public MiddleEar
{
public:
	// constructors
	AdultModel();
	AdultModel(int freq_range);

	// functions acting on data
	void combinedModel();
	void keefe(); // move to private when done implementing

private:
	DataArray DataKeefe;
	DataArray DataCombined;
};










#endif