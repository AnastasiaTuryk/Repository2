#include"Restaurant.h"
#include"Command.h"
#include<iostream>
using namespace std;
Restaurant::Restaurant(string name, string design, string kitchen, int rating, float price): Establishment(name,design,price)
{
	this->kitchen = kitchen;
	this->rating = rating;
}
/*void Restaurant::RestaurantInformation(string name, string design, string kitchen, int rating,float price)
{

	this->name = name;
	this->design = design;
	this->kitchen = kitchen;
	this->rating = rating;
	this->price = price;
}*/

void Restaurant::Write()
{
	cout << endl;
	cout << "information about restaurant:" << endl<<endl;
	cout << "name:" << name << endl << "design:" << design << endl << "kitchen:" << kitchen << endl << "rating:" << rating <<endl<<"average price:"<<price<< endl;
}

string Restaurant::getdesign()
{
	return design;
}
string Restaurant::getname()
{
	return name;
}
string Restaurant::getkitchen()
{
	return kitchen;
}
int Restaurant::getrating()
{
	return rating;
}
float Restaurant::getprice()
{
	return price;
}