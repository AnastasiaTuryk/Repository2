#ifndef PERSON_H
#define PERSON_H
#include<string>
#include<iostream>
using namespace std;

class Person
{
public: 
	string name = "";
	Person(string name)
	{
		this->name = name;
	}

	void addPerson(string name)
	{
		this->name = name;
	}

	virtual void WriteInfo()
	{
		cout <<name<<endl;
	}
};
#endif

