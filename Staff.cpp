#include"Staff.h"
#include<string>
#include<iostream>
using namespace std;

Staff::Staff(string name, string position, int experience,int rating) :Person(name)
{
	this->position = position;
	this->experience = experience;
	this->rating = rating;
}

void Staff:: StaffInformation(string name, string position, int experience,int rating)
{
	this->name = name;
	this->position = position;
	this->experience = experience;
	this->rating = rating;
}


string Staff::getposition()
{
	return position;
}
void Staff::setposition(string position)
{
	this->position = position;
}

void Staff::setexperience(int experience)
{
	this->experience = experience;
}

int Staff::getexperience()
{
	return experience;
}

int Staff::getrating()
{
	return rating;
}

void Staff::Write()
{
	cout << "name: " << name << endl << "position: " << position << endl << "experience: " << experience << endl << "rating: " << rating << endl;;
	cout << endl;
}

