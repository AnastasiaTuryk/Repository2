#include"Client.h"
#include"Command.h"
#include"Restaurant.h"
#include"Staff.h"
#include"Person.h"
#include"Provider.h"

#include<string>
#include<iostream>
using namespace std;


int main()
{
	Command cmd;
	cmd.RestaurantShow();
	cmd.ShowClient();
	cmd.ShowStaff();
	cmd.ShowProvider();
	bool menu = false;
	cout << "\t\t\t\t\tHELLO! You are greeted by a chain of restaurants!!!" << endl << endl;
	while (true)
	{
		cout << "\t\t\t\t\t\t\tChoose that you want:" << endl << endl;

		cout << "0-to exit!" << endl;
		cout << "1-to see all available restaurant" << endl;
		cout << "2-to see the list of staff" << endl;
		cout << "3-to see the list of client" << endl;
		cout << "4-to see the list of provider" << endl;
		cout << "5-to order a table in restaurant" << endl << endl;
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
			cmd.WriteRestaurant();
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
					cmd.AddRestaurant();
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
			//cmd.ShowAllStaff();
			cmd.printAll("Staff:",cmd.vStaff);
			cout << endl;
			bool isOkay = false;
			while(isOkay==false)
			{
				cout << "1-to see the top rating of employeer" << endl;
				cout << "2-add employeer to the list" << endl;
				cout << "3-change the rating" << endl;
				cout << "4-to delete the employeer" << endl;
				cout << "5-to exit" << endl;
				cout << endl;
				int onemoreInput;cin >> onemoreInput;
				if (onemoreInput == 1)
				{
					cmd.ShowTopRatingStaff();
				}
				else if (onemoreInput == 2)
				{
					cmd.AddStaff();
				}
				else if (onemoreInput == 3)
				{
					cmd.ChangeRatingStaff();
				}
				else if(onemoreInput == 4)
				{
					cmd.ShowAllStaff();
					cout << "input the number of staff that you want to delete" << endl;
					int tmp;cin >> tmp;
					cmd.deleteStaff(tmp - 1);
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
			//cmd.ShowAllClient();
			cmd.printAll("Client:",cmd.myClient);
			bool isRight = false;
			while (isRight == false)
			{
				cout << endl;
				cout << "1-add bonus card" << endl;
				cout << "2-delete client" << endl;
				cout << "3-exit" << endl;
				int value;cin >> value;
				if (value == 1)
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
				else if(value==2)
				{
					cmd.ShowAllClient();
					int num;cout << "input the number of client that you delete" << endl;cin >> num;
					cmd.deleteClient(num - 1);
				}
				else
				{
					isRight = true;
					break;
				}

			}
			break;
		}
		case 4:
		{
			//cmd.ShowAllProvider();
			cmd.printAll("Provider:", cmd.vProvider);
			bool isUser = false;
			while (isUser == false)
			{
				cout << "1-delivery to restaurant" << endl;
				cout << "2-change rating of courier" << endl;
				cout << "3-exit" << endl;
				int user;cin >> user;
				if (user == 1)
				{
					cmd.Delivery();
				}
				else if (user == 2)
				{
					cmd.ChangeRatingProvider();
				}
				else
				{
					isUser = true;
					break;
				}
			}
			break;
		}
		case 5:
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