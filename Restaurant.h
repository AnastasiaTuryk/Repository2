#ifndef RESTAURANT_H
#define RESTAURANT_H
#include<string>
#include<iostream>
#include"Establishment.h"
using namespace std;

class Restaurant :public Establishment
{
protected:
	string kitchen;

public:
	int rating;
	Restaurant(string = "", string = "", string = "", int = 0, float = 0);
	//void RestaurantInformation(string name, string design, string kitchen, int rating,float price);
	void Write();

	int getrating();
	string getname();
	string getkitchen();
	float getprice();
	string getdesign();
};
#endif // !RESTURANT_H

