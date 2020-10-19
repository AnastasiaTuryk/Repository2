#include"Client.h"
#include"Command.h"
#include"Restaurant.h"
#include"Staff.h"
#include"Person.h"
#include"Provider.h"
#include"Repository.h"

#include<string>
#include<iostream>
using namespace std;


int main()
{
	Command cmd;
	//cmd.RestaurantShow();
	//cmd.ShowClient();
	//cmd.ShowStaff();
	//cmd.ShowProvider();
	cmd.printAll();
	bool menu = false;
	cout << "\t\t\t\t\tHELLO! You are greeted by a chain of restaurants!!!" << endl << endl;
	while (true)
	{
		cout << "\t\t\t\t\t\t\tChoose that you want:" << endl << endl;

		cout << "0-to exit!" << endl;
		cout << "1-to see all available restaurant" << endl;
		cout << "2-actions with people" << endl;
		cout << "3-to order a table in restaurant" << endl << endl;
		cout << "input your number:";

		int Input;
		cin >> Input;

		switch (Input)
		{
		case 0:
			menu = true;
			break;
		case 1:
		{
			cmd.printRestaurant();
			cout << endl << endl;
			bool isBool = false;
			while (isBool==false)
			{
				cout << endl;
				cout << "1-to see the highest rated restaurant" << endl;
				cout << "2-to change rating of restaurant" << endl;
				cout << "3-to see the restaurant with lowest price" << endl;
				cout << "4-add the restaurant" << endl;
				cout << "5-exit" << endl;

				int newInput;
				cin >> newInput;
				if (newInput == 1)
				{
					cmd.ShowHighRating();
				}
				else if (newInput == 2)
				{
					cmd.ChangeRating();
					cout << "\tRating is changed!" << endl;
				}
				else if (newInput == 3)
				{
					cmd.ShowLowPrice();
				}
				else if (newInput == 4)
				{
					cout << "input the restaurant info" << endl;
					string name;string design;string kitchen;float price;int rating;
					cout << "name: ";cin >> name;cout << "design: ";cin >> design;
					cout << "kitchen: ";cin >> kitchen;cout << "rating: ";cin >> rating;
					cout << "average price: ";cin >> price;
					Restaurant r;
					r = Restaurant(name, design, kitchen,rating,price);
					try
					{
						cmd.addRestaurant(r);
					}
					catch (const char* err)
					{
						cout << err << endl;
					}
				}
				else if (newInput == 5)
				{
					isBool = true;
					break;
				}
			}
			break;
		}
		case 2:
		{
			cout << endl;
			bool isOkay = false;
			while(isOkay==false)
			{
				cout << "1-to see the list of client" << endl;
				cout << "2-to see the list of staff" << endl;
				cout << "3-to see the list of provider" << endl;
				cout << "4-to exit" << endl;
				cout << endl;
				int onemoreInput;cin >> onemoreInput;
				if (onemoreInput == 1)
				{
					cmd.write("Client");
					bool tnp = false;
					while (tnp == false)
					{
						cout << "1-to add the client" << endl;
						cout << "2-to add the bonus" << endl;
						cout << "3-exit" << endl;
						int inputTwo;cin >> inputTwo;
						if (inputTwo == 1)
						{
							cout << "input the client info" << endl;
							string name;string surname;int discount;
							cout << "name: ";cin >> name;cout << "surname:";cin >> surname;cout << "discount:";
							cin >> discount;
							Client c;
							c = Client(name, surname, discount);
							try
							{
								cmd.AddClient(c);
							}
							catch (const char* err)
							{
								cout << err << endl;
							}
						}
						else if (inputTwo == 2)
						{
							cout << "wanna customer card?" << endl << "1-yes\n2-no" << endl;
							int newValue;cin >> newValue;
							if (newValue == 1)
							{
								string name;string surname;
								cout << "input your name: ";cin >> name;
								cout << "input your surname: ";cin >> surname;
								cmd.rewrite(name, surname);
								cout << "thank you!your discount is credited!" << endl;
							}
							else
							{
								cout << "okay!" << endl << endl;
							}
						}
						else
						{
							tnp = true;
							break;
						}
					}
					break;
				}
				else if (onemoreInput == 2)
				{
					cmd.write("Staff");
					bool eVRO = false;
					while (eVRO == false)
					{
						cout << "\t\t\t1-add staff" << endl;
						cout << "\t\t\t2-change rating" << endl;
						cout << "\t\t\t3-to see the top rating" << endl;
						cout << "\t\t\t4-exit" << endl;
						int inputThree;cin >> inputThree;
						if (inputThree==1)
						{
							string name;string position;int experience;int rating;
							cout << "name: ";cin >> name;
							cout << "position:";cin >> position;cout << "experience: ";cin >> experience;cout << "rating: ";cin >> rating;
							Staff s;
							s = Staff(name, position, experience, rating);
							cmd.AddStaff(s);
						}
						else if (inputThree==2)
						{
							cmd.ChangeRatingStaff();
						}
						else if (inputThree==3)
						{
							cmd.ShowTopRatingStaff();
						}
						else
						{
							eVRO = true;
							break;
						}
					}
					break;
				}
				else if (onemoreInput == 3)
				{
					cmd.write("Provider");
					bool user4 = false;
					while (user4 == false)
					{
						cout << "\t\t\t\t1-to add provider" << endl;
						cout << "\t\t\t\t2-to change rating" << endl;
						cout << "\t\t\t\t3-exit" << endl;
						int inputFour;cin >> inputFour;
						if (inputFour == 1)
						{
							string name;int rating;string country;
							cout << "name: ";cin >> name;cout << "rating: ";cin >> rating;cout << "country: ";cin >> country;
							Provider pr;
							pr = Provider(name, rating, country);
							cmd.AddProvider(pr);
						}
						else if (inputFour==2)
						{
							cmd.ChangeRatingProvider();
						}
						else if (inputFour==3)
						{
							user4= true;
							break;
						}
					}
				}

				else
				{
					isOkay = true;
					break;
				}
			}
			break;
		}
		case 3:
		{
			cmd.Order();  
			break;
		}
		default:
			break;
		}
		if (menu)
			break;
	}
	return 0;
}