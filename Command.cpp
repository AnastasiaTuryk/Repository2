#include"Command.h"

//дочірні класи 
#include"Client.h"
#include"Staff.h"
#include"Provider.h"

#include"Restaurant.h"

#include<fstream>
#include<iostream>
#include<string>
using namespace std;


void Command::ShowProvider()
{
	string name;
	int rate;
	string country;
	ifstream fin("Provider.txt");
	if (!fin.is_open())
	{
		cout << "your file is not open!" << endl;
	}
	while (fin)
	{
		if (fin >> name >> rate >> country)
		{
			Provider* pr = new Provider(name,rate, country);
			vProvider.push_back(pr);
		}
	}
	fin.close();
}

void Command::ShowAllProvider()
{
	cout << "\t\tProvider:" << endl;
	for (int i = 0;i < vProvider.size();i++)
	{
		cout << "№" << i + 1;
		vProvider[i]->WriteInfo();
	}
}




void Command::ShowClient()
{
	string name;string surname;int discount;
	ifstream fin("Client.txt");
	if (!fin.is_open())
	{
		cout << "your file is not open!" << endl;
	}
	while (fin)
	{
		if (fin >> name >> surname>>discount)
		{
			//Client c;
			//c.ClientInformation(name, phone);
			Client* c = new Client(name,surname,discount);
			myClient.push_back(c);
		} 
	}
	fin.close();
}

void Command::ShowStaff()
{
	string name;
	string position;
	int experience;
	int rating;
	ifstream fin("Staff.txt");
	if (!fin.is_open())
	{
		cout << "your file is not open!" << endl;
	}
	while (fin)
	{
		if (fin >> name >> position >> experience >> rating)
		{
			//Staff s;
			//s.StaffInformation(name, position,experience);
			Staff* s = new Staff(name, position, experience,rating );
			vStaff.push_back(s);
		}
	}
	fin.close();
}





void Command::printAll(string str,vector<Person*>pers)
{
	cout << "\t\t\t\t\t" << str << endl;
	for (int i = 0;i < pers.size();i++)
	{
		pers[i]->WriteInfo();
		cout << endl;
	}
}

void Command::ShowAllStaff()
{
	cout << "\t\tStaff:" << endl;
	for (int i = 0;i < vStaff.size();i++)
	{
		cout << "№" << i + 1;
		vStaff[i]->WriteInfo();
	}
}


void Command::ShowAllClient()
{
	cout << "\t\tClient:" << endl;
	for (int i = 0;i < myClient.size();i++)
	{
		cout << "№" << i + 1;
		myClient[i]->WriteInfo();
	}
}



void Command::ShowTopRatingStaff()
{
	int size = vStaff.size();
	int* arr = new int[size];
	int tmp = 0;string name;int experience;string position;
	for (int i = 1;i < vStaff.size();i++)
	{
		for (int j = 0;j < (vStaff.size() - i); j++)
		{
			if (((Staff*)vStaff[j])->rating < ((Staff*)vStaff[j + 1])->rating)
			{
				name=((Staff*)vStaff[j])->name;
				((Staff*)vStaff[j])->name = ((Staff*)vStaff[j + 1])->name;
				((Staff*)vStaff[j + 1])->name = name;

				experience = ((Staff*)vStaff[j])->getexperience();
				position = ((Staff*)vStaff[j])->getposition();
				((Staff*)vStaff[j])->setexperience(((Staff*)vStaff[j + 1])->getexperience());
				((Staff*)vStaff[j])->setposition(((Staff*)vStaff[j + 1])->getposition());
				((Staff*)vStaff[j + 1])->setexperience(experience);
				((Staff*)vStaff[j + 1])->setposition(position);

				tmp = ((Staff*)vStaff[j])->rating;
				((Staff*)vStaff[j])->rating = ((Staff*)vStaff[j + 1])->rating;
				((Staff*)vStaff[j + 1])->rating = tmp;
			}
		}
	}
	for (int i= 0;i < vStaff.size();i++)
	{
		((Staff*)vStaff[i])->WriteInfo();
	}
}

void Command::ChangeRatingStaff()
{
	string name;cout << "input the name of employeer: " << endl;cin >> name;
	int newrate = 0;
	for (int i = 0;i < vStaff.size();i++)
	{
		if (vStaff[i]->name == name)
		{
			cout << "input new rate:" << endl;
			cin >> newrate;
			((Staff*)vStaff[i])->rating = newrate;
		}
	}

}
void Command::ChangeRatingProvider()
{
	string name;
	cout << "type the name:" << endl;
	cin >> name;
	int newrate=0;
	for (int i = 0;i < vProvider.size();i++)
	{
		if (vProvider[i]->name == name)
		{
			cout << "write the new rate:" << endl;
			cin >> newrate;
			((Provider*)vProvider[i])->rate = newrate;
			//break;
		}
	}
}

void Command::AddStaff()
{
	ofstream fout("Staff.txt", ios_base::app);
	if (!fout)
		throw"sorry,your file is not open";

	while (fout)
	{
		string name;cout << "name:";cin >> name;
		int rating;string position;int experience;
		cout << "position:";
		cin >> position;
		cout << "experience:";
		cin >> experience;
		cout << "rating:";
		cin >> rating;

		cout << endl << endl;
		Staff* staff = new Staff(name, position, experience, rating);
		vStaff.push_back(staff);
		break;
	}
	fout.close();
}

void Command::deleteStaff(int i)
{
	
	vStaff.erase(vStaff.begin() + i);
	ShowAllStaff();
	cout << "employeer is deleted!" << endl;
}

void Command::deleteClient(int i)
{
	myClient.erase(myClient.begin() + i);
	ShowAllClient();
	cout << "client is deleted!" << endl;
}

void Command::rewrite(string name, string surname)
{
	int m = 0;
	for (int i = 0;i < myClient.size();i++)
	{
		if ((name == ((Client*)myClient[i])->getname() && (surname == ((Client*)myClient[i])->getsurname())))
		{
			((Client*)myClient[i])->setdiscount(((Client*)myClient[i])->getdiscount() + 1);
			m++;
		}
	}
	if (m == 0)
	{
		Client* cl = new Client(name, surname, 1);
		myClient.push_back(cl);
	}
	ofstream str;
	str.open("Client.txt");
	for (int i = 0;i < myClient.size();i++)
	{
		str << ((Client*)myClient[i])->getname()<<" "<< ((Client*)myClient[i])->getsurname()
			<<" " << ((Client*)myClient[i])->getdiscount() << endl;
	}
	str.close();
}


void Command::Delivery()
{
	
	string name;
	cout << "type the courier name:";cin >> name;
	for (int i = 0;i < vProvider.size();i++)
	{
		if (name == ((Provider*)vProvider[i])->name)
		{
			vProvider.erase(vProvider.begin() + i);
		}
	}
	ofstream fout("ProductDelivery.txt",ios_base::app);
	if (!fout)
	{
		cout << "your file is not open!";
	}
	while (fout)
	{
		cout << "type the product: ";
		string products;cin>>products;
		fout << products;fout <<" ";
		cout << "\t\t\tall available restaurant" << endl;
		WriteRestaurant();
		string namerestaurant;cout << "input the restaurant name: ";cin >> namerestaurant;
		fout << namerestaurant;
		cout << "your order " << products << " , to be adressed to " << namerestaurant << ",by delivery " << name << endl;
		break;
	}
	fout.close();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Command::ChangeRating()
{
	int rate;
	string lastname;
	cout  << "you choose to change rating of restaurant:" << endl;
	cout << "type the name:" << endl;
	cin >> lastname;
	for (int i = 0;i < myRestaurant.size();i++)
	{
		if (myRestaurant[i]->name == lastname)
		{
			cout << "how many points do you want to put?" << endl;
			cin >> rate;
			if (rate < 0 && rate < 6)
				break;
			myRestaurant[i]->rating = rate;
			break;
			
		}
	}
}

void Command::RestaurantShow()
{
	string name;
	string design;
	string kitchen;
	int rating;
	float price;
	ifstream fin("Restaurant.txt");
	if (!fin.is_open())
	{
		cout << "your file is not open!" << endl;
	}
	while(fin)
	{
		if (fin >> name >> design >> kitchen >> rating >> price)
		{
			Restaurant* r=new Restaurant(name,design,kitchen,rating,price);
			//Restaurant r;
			//r.RestaurantInformation(name, design, kitchen, rating,price);
			myRestaurant.push_back(r);//delete myRestaurant[i]
		}
	}
	fin.close();
}



void Command::WriteRestaurant()
{
	for (int i = 0;i < myRestaurant.size();i++)
	{
		myRestaurant[i]->Write();
	}
}

void Command::Order()
{
	string firstname;

	cout << "Welcome,here you can to order a table!" << endl;
	cout << "type the restaurant name:";
	cin >> firstname;
	for (int i = 0;i < myRestaurant.size();i++)
	{
		if (firstname == myRestaurant[i]->name)
		{
			myRestaurant.erase(myRestaurant.begin() + i);//erase the i-th element
		}
	}
	ofstream fout("Client.txt",ios_base::app);
	if (!fout)
	{
		cout << "your file is not open!";
	}
	while (fout)
	{
		cout << "you need to leave data to order:" << endl;
		string nameclient;
		cout << "please,input your name: ";
		cin >> nameclient;
		string surname;cout << "input your surname: ";cin >> surname;
		int discount;
		cout << "your discount: ";cin >> discount;
		Client* cl=new Client(nameclient,surname,discount);
		fout << nameclient << " " << surname << " " << discount << endl;
		cout << "Thank you! We recorded your contacts!Our manager will contact with you soon!" << endl;
		break;
	}
	fout.close();
}

void Command::AddRestaurant()
{
	cout << "here you can add the restaurants to our list:" << endl;

	ofstream fout("Restaurant.txt", ios_base::app);
	if (!fout)
		throw"sorry,your file is not open";

	while (fout)
	{
		string name;
		cout << "please,input the restaurant name:";
		cin >> name;
		int rating;string design;string kitchen;float price;
		cout << "restaurant design:";
		cin >> design;
		cout << "kitchen:";
		cin >> kitchen;
		cout << "restaurant rating:";
		cin >> rating;
		cout << "average price:" << endl;
		cin >> price;
		cout << endl << endl;
		Restaurant r;

		cout << "Thank you! We have written down your wishes and we will make in base." << endl;
		fout << name << " " << design << " " << kitchen << " " << rating << " " << price;
		r.RestaurantInformation(name, design, kitchen, rating, price);
		break;
	}
	fout.close();
}

void Command::ShowHighRating()
{
	int max = myRestaurant[0]->rating;
	int index = 0;
	for (int i = 1;i < myRestaurant.size();i++)
	{
		if (max < myRestaurant[i]->rating)
		{
			max = myRestaurant[i]->rating;
			index = i;
		}
	} 
	cout << endl;
	cout << "info about restaurant with highest rating:" << endl;
	myRestaurant[index]->Write();
}

void Command::ShowLowPrice()
{
	int min = myRestaurant[0]->price;
	int index = 0;
	for (int i = 1;i < myRestaurant.size();i++)
	{
		if (min > myRestaurant[i]->price)
		{
			min = myRestaurant[i]->price;
			index = i;
		}
	}
	cout << endl;
	cout << "info about restaurnt with average the lowest price:" << endl;
	myRestaurant[index]->Write();
}

Command::~Command()
{
	for (int i = 0;i < myRestaurant.size();i++) {
		delete myRestaurant[i];
	}
	for (int i = 0;i < myClient.size();i++)
	{
		delete myClient[i];
	}
	for (int i = 0;i < vStaff.size();i++)
	{
		delete vStaff[i];
	}
	for (int i = 0;i < pers.size();i++)
	{
		delete pers[i];
	}
}