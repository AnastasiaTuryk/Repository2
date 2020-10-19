
#ifndef COMMAND_H
#define COMMAND_H
#include"Restaurant.h"
#include"Client.h"
#include"Staff.h"
#include"Provider.h"
#include"Person.h"

#include"ClientRepository.h"
#include"ProviderRepository.h"
#include"RestaurantRepository.h"
#include"StaffRepository.h"

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Command
{

public:
	//vector <Restaurant*> myRestaurant;
	//vector<Person*> myClient;
	//vector<Person*> vStaff;
	//vector<Person*> vProvider;
	vector<Person*> pers;
	vector<Establishment*> estab;


	//void RestaurantShow();
	//void ShowClient(); 
	//void ShowStaff();
	//void ShowAllStaff();
	//void ShowAllClient();
	RestaurantRepository restaurantRepository = RestaurantRepository(true);

	ClientRepository clientRepository = ClientRepository(true);
	StaffRepository staffRepository = StaffRepository(true);
	ProviderRepository providerRepository = ProviderRepository(true);
	//void Write();
	void printAll();

	void write(string str);
	//void writeProvider();
	//void writeClient();
	void printRestaurant();

	void AddClient(Client &client);
	void AddStaff(Staff& staff);
	void AddProvider(Provider& provider);
	void addRestaurant(Restaurant& restaurant);

	void ShowTopRatingStaff();
	void ChangeRatingStaff();

	void rewrite(string, string);


	void ChangeRatingProvider();

	void Order();
	void ChangeRating();
	void ShowHighRating();
	void ShowLowPrice();

	~Command();
	
};
#endif // !COMMAND_H
