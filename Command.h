
#ifndef COMMAND_H
#define COMMAND_H
#include"Restaurant.h"
#include"Client.h"
#include"Staff.h"

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Command
{

public:
	vector <Restaurant*> myRestaurant;
	vector<Person*> myClient;
	vector<Person*> vStaff;
	vector<Person*> vProvider;
	vector<Person*> pers;


	void RestaurantShow();
	void ShowClient(); 
	void ShowStaff();


	void ShowAllStaff();
	void ShowAllClient();
	void printAll(string,vector<Person*>person);

	void ShowTopRatingStaff();
	void ChangeRatingStaff();
	void AddStaff();
	void deleteStaff(int);

	void deleteClient(int);
	void rewrite(string, string);

	void ShowProvider();
	void ShowAllProvider();
	void ChangeRatingProvider();
	void Delivery();

	void AddRestaurant();
	void WriteRestaurant();
	void Order();
	void ChangeRating();
	void ShowHighRating();
	void ShowLowPrice();

	~Command();
	
};
#endif // !COMMAND_H
