#ifndef ESTABLISHMENT_H
#define ESTABLISHMENT_H
#include<string>
#include<iostream>
#include "Entity.h"
using namespace std;

class Establishment:public Entity
{
public:
	string name = "";
	string design = "";
	float price;
	Establishment(string name,string design,float price)
	{
		this->name = name;
		this->design = design;
		this->price = price;
	}

	virtual void Write()
	{
		cout <<name<<" "<<design<<" "<<price<< endl;
	}
};
#endif
