#include <iostream>
#include <string>
#include "MiddleEar.h"
#include "AdultModel.h"

using namespace std;

int main(int argc, char** argv) {

	cout << "Enter frequency range : ";
	int freq_range;
	cin >> freq_range;
	
	cin.ignore();
	cout << "Enter pressure range : ";
	int press;
	cin >> press;


	//AdultModel temp(freq_range, press);
	AdultModel temp(freq_range);
	
	//MiddleEar middle(freq_range);
	
	temp.deriv(1);


	// test store functionallity
	
	cin.ignore();
	cout << "\n Enter save name or leave blank : ";
	string name;
	getline(cin, name);
	
	temp.setName(name);
	temp.storeData(AdultModel::IMPEDANCE);
	//temp.storeData(AdultModel::ADMITTANCE);
	//temp.storeData(AdultModel::PRESSURE);
	//temp.storeData(AdultModel::DERIVATIVE);
	
	
	
	
	
	/*

	cout << "Enter age : \n";
	cin >> test;
	
	temp.setAge(test);

	int inputAge = temp.getAge();
	
	cout << "\n Age is : " << inputAge;
	*/
		
	cout << "\n\n Speed of sound is : " << temp.getSpeedofSound();
	
	//temp.setDiameter(1.2358f);

	cout << "\n\n ear-canal diameter is now : " << temp.getDiameter();

	cout << "\n\n float check : " << temp.getLength();

	

	return 0;

}
