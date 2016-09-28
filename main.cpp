#include <iostream>
#include "MiddleEar.h"

using namespace std;

int main(int argc, char** argv) {

	cout << "Enter frequency range : ";
	int freq_range;
	cin >> freq_range;
	
	MiddleEar temp(freq_range);
	//int test;

	/*

	cout << "Enter age : \n";
	cin >> test;

	
	temp.setAge(test);

	int inputAge = temp.getAge();
	
	cout << "\n Age is : " << inputAge;
	*/
		
	cout << "\n\n Speed of sound is : " << temp.getSpeedofSound();
	
	temp.setDiameter(1.2358f);

	cout << "\n\n ear-canal diameter is now : " << temp.getDiameter();

	cout << "\n\n float check : " << temp.getLength();

	return 0;

}
