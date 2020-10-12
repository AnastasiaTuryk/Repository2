#include"Client.h"
#include"Command.h"
//#include"Person.h"
#include<iostream>
#include<string>
using namespace std;

Client::Client(string name,string surname,int discount): Person(name)
{
	this->surname = surname;
	this->discount = discount;
	
}
void Client::ClientInformation(string name,string surname,int discount) 
{
	this->name = name;
	this->surname = surname;
	this->discount = discount;
}

void Client::WriteInfo()
{
	cout << "info about guest:" << name << " " << surname <<" "<<discount<<endl;
}

void Client::addClient(string name, string surname,int discount)
{
	addPerson(name);
	this->surname = surname;
	this->discount = discount;
}
string Client::getname()
{
	return name;
}
string Client::getsurname()
{
	return surname;
}

void Client::setdiscount(int discount)
{
	this->discount = discount;
}

int Client::getdiscount()
{
	return discount;
}