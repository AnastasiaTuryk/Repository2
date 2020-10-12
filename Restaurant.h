#ifndef RESTAURANT_H
#define RESTAURANT_H
#include<string>
#include<iostream>
using namespace std;

class Restaurant
{
protected:
	string design;
	string kitchen;

public:
	string name;
	int rating;
	float price;
	Restaurant(string = "", string = "", string = "", int = 0, float = 0);
	void RestaurantInformation(string name, string design, string kitchen, int rating,float price);
	void Write();

};
#endif // !RESTURANT_H

