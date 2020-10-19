#ifndef PERSON_H
#define PERSON_H
#include<string>
#include<iostream>
#include "Entity.h"
using namespace std;

class Person :public Entity
{
public: 
	string name = "";
	Person(string name)
	{
		this->name = name;
	}
	string getname()
	{
		return name;
	}
	void setname(string name)
	{
		this->name = name;
	}
	virtual void Write()
	{
		cout <<name<<endl;
	}
};
#endif

