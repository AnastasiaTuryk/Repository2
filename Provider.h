#ifndef PROVIDER_H
#define PROVIDER_H
#include"Person.h"
#include<string>
#include<iostream>
using namespace std;

class Provider :public Person
{
protected:
	string country;
	//int rate;
public:
	int rate;
	Provider(string = "", int=0,string = "");
	void ProviderInformation(string name,int rate,string country);
	void WriteInfo();
	int getrating();
};
#endif

