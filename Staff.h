#ifndef STAFF_H
#define STAFF_H
#include"Person.h"
#include<string>
#include<iostream>
using namespace std;

class Staff:public Person
{
protected:
	string position;
	int experience;
public:

	int rating;

	Staff(string = "", string = "", int = 0,int=0);

	void StaffInformation(string name, string position, int experience,int rating);

	void Write() override;

	string getposition();
	void setposition(string);
	void setexperience(int);
	int getexperience();

	int getrating();


};
#endif

