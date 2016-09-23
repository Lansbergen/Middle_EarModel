#include <iostream>
#include "MiddleEar.h"

using namespace std;

int main(int argc, char** argv) {

	MiddleEar temp;
	int test;

	cout << "Enter age : \n";
	cin >> test;

	temp.setAge(test);

	int inputAge = temp.getAge();
	
	cout << "\n Age is : " << inputAge;

	int speedofsound = temp.getSpeedofLight();
	
	cout << "\n\n Speed of sound is : " << temp.getSpeedofLight();
	
	/*
	cout << "\n\n Enter diameter Ear-canal : ";
	double diameter;
	cin >> diameter;
	temp.setDiameter(diameter);
	*/
	temp.setDiameter();

	cout << "\n\n ear-canal diameter is now : " << temp.getDiameter();

	return 0;

}
