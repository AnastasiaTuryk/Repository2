#include"Restaurant.h"
#include"Command.h"
#include<iostream>
using namespace std;
Restaurant::Restaurant(string name, string design, string kitchen, int rating, float price)
{
	this->name = name;
	this->design = design;
	this->kitchen = kitchen;
	this->rating = rating;
	this->price = price;
}
void Restaurant::RestaurantInformation(string name, string design, string kitchen, int rating,float price)
{

	this->name = name;
	this->design = design;
	this->kitchen = kitchen;
	this->rating = rating;
	this->price = price;
}

void Restaurant::Write()
{
	cout << endl;
	cout << "information about restaurant:" << endl<<endl;
	cout << "name:" << name << endl << "design:" << design << endl << "kitchen:" << kitchen << endl << "rating:" << rating <<endl<<"average price:"<<price<< endl;
}