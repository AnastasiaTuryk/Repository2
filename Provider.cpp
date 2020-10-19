#include"Provider.h"
#include<string>
#include<iostream>
using namespace std;

Provider::Provider(string name, int rate, string country) :Person(name)
{
	this->name = name;
	this->rate = rate;
	this->country = country;
}

/*void Provider::ProviderInformation(string name, int rate,string country)
{
	addPerson(name);
	this->rate = rate;
	this->country = country;
}*/

void Provider::Write()
{
	cout << "name: " << name << endl<< "rating: " << rate << endl << "country: " << country << endl;
	cout << endl;
}

int Provider::getrating()
{
	return rate;
}

string Provider::getcountry()
{
	return country;
}