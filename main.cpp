#include <iostream>
#include <string>
#include "MiddleEar.h"
#include "AdultModel.h"

using namespace std;

int main(int argc, char** argv) {

	cout << "Enter frequency range : ";
	int freq_range;
	cin >> freq_range;
	
	

	//MiddleEar temp(freq_range);
	
	AdultModel temp(freq_range);
	
	temp.keefe();

	cout << "\nEnter freq index for refenrnce testing getData : ";
	int ind;
	cin.ignore();
	cin >> ind;

	cout << "Data -> : " << temp.getData(ind);

	// test store functionallity
	/*
	cin.ignore();
	cout << "\n Enter save name or leave blank : ";
	string name;
	getline(cin, name);
	
	temp.setName(name);

	temp.storeData();

	*/
	
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
