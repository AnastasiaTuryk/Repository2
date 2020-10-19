#include"Command.h"

//дочірні класи 
#include"Client.h"
#include"Staff.h"
#include"Provider.h"

#include"Restaurant.h"
#include"Repository.h"

#include<fstream>
#include<iostream>
#include<string>
using namespace std;


/*void Command::ShowProvider()
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
}*/

/*void Command::ShowAllProvider()
{
	cout << "\t\tProvider:" << endl;
	for (int i = 0;i < vProvider.size();i++)
	{
		cout << "№" << i + 1;
		vProvider[i]->WriteInfo();
	}
}*/

/*void Command::ShowClient()
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
}*/

/*void Command::ShowStaff()
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
}*/

void Command::addRestaurant(Restaurant& restaurant)
{
	restaurantRepository.Add(restaurant);
}

void Command::AddClient(Client& client)
{
	clientRepository.Add(client);
}

void Command::AddProvider(Provider& provider)
{
	providerRepository.Add(provider);
}

void Command::AddStaff(Staff& staff)
{
	staffRepository.Add(staff);
}

/*void Command::printAll(string str,vector<Person*>pers)
{
	cout << "\t\t\t\t\t" << str << endl;
	for (int i = 0;i < pers.size();i++)
	{
		pers[i]->WriteInfo();
		cout << endl;
	}
}*/

void Command::printRestaurant()
{
	for (int i = 0; i < restaurantRepository.GetEntity().size(); i++) {
		(restaurantRepository.GetEntity()[i])->Write();
		//cout << endl;

		//estab[i]->Write();
	}
}

void Command::printAll()
{
	pers.clear();

	for (int i = 0; i < clientRepository.GetEntity().size(); i++) {
		pers.push_back((Client*)clientRepository.GetEntity()[i]);
	}
	for (int i = 0; i < staffRepository.GetEntity().size(); i++) {
		pers.push_back((Staff*)staffRepository.GetEntity()[i]);
	}
	for (int i = 0;i < providerRepository.GetEntity().size();i++)
	{
		pers.push_back((Provider*)providerRepository.GetEntity()[i]);
	}
}
void Command::write(string str)
{
	printAll();
	if (str == "Client")
	{
		cout << "information about clients:" << endl;
		for (int i = 0;i < clientRepository.GetEntity().size();i++)
		{
			(clientRepository.GetEntity()[i])->Write();
		}
	}
	else if(str=="Staff")
	{
		cout << "information about staffs:" << endl;
		for (int i = 0;i < staffRepository.GetEntity().size();i++)
		{
			(staffRepository.GetEntity()[i])->Write();
		}
	}
	else if(str=="Provider")
	{
		cout << "information about providers:" << endl;
		for (int i = 0;i < providerRepository.GetEntity().size();i++)
		{
			(providerRepository.GetEntity()[i])->Write();
		}
	}
}


void Command::ShowTopRatingStaff()
{
	//int size = vStaff.size();
	//int* arr = new int[size];
	int tmp = 0;string name;int experience;string position;
	for (int i = 1;i < staffRepository.GetEntity().size();i++)
	{
		for (int j = 0;j < (staffRepository.GetEntity().size() - i); j++)
		{
			if (((Staff*)staffRepository.GetEntity()[j])->rating < ((Staff*)staffRepository.GetEntity()[j + 1])->rating)
			{
				name=((Staff*)staffRepository.GetEntity()[j])->name;
				((Staff*)staffRepository.GetEntity()[j])->name = ((Staff*)staffRepository.GetEntity()[j + 1])->name;
				((Staff*)staffRepository.GetEntity()[j + 1])->name = name;

				experience = ((Staff*)staffRepository.GetEntity()[j])->getexperience();
				position = ((Staff*)staffRepository.GetEntity()[j])->getposition();
				((Staff*)staffRepository.GetEntity()[j])->setexperience(((Staff*)staffRepository.GetEntity()[j + 1])->getexperience());
				((Staff*)staffRepository.GetEntity()[j])->setposition(((Staff*)staffRepository.GetEntity()[j + 1])->getposition());
				((Staff*)staffRepository.GetEntity()[j + 1])->setexperience(experience);
				((Staff*)staffRepository.GetEntity()[j + 1])->setposition(position);

				tmp = ((Staff*)staffRepository.GetEntity()[j])->rating;
				((Staff*)staffRepository.GetEntity()[j])->rating = ((Staff*)staffRepository.GetEntity()[j + 1])->rating;
				((Staff*)staffRepository.GetEntity()[j + 1])->rating = tmp;
			}
		}
	}
	for (int i= 0;i < staffRepository.GetEntity().size();i++)
	{
		((Staff*)staffRepository.GetEntity()[i])->Write();
	}
}

void Command::ChangeRatingStaff()
{
	string name;cout << "input the name of employeer: " << endl;cin >> name;
	int newrate = 0;
	for (int i = 0;i < staffRepository.GetEntity().size();i++)
	{
		if (((Staff*)staffRepository.GetEntity()[i])->name == name)
		{
			cout << "input new rate:" << endl;
			cin >> newrate;
			((Staff*)staffRepository.GetEntity()[i])->rating = newrate;
		}
	}

}
void Command::ChangeRatingProvider()
{
	string name;
	cout << "type the name:" << endl;
	cin >> name;
	int newrate=0;
	for (int i = 0;i < providerRepository.GetEntity().size();i++)
	{
		if (((Provider*)providerRepository.GetEntity()[i])->name == name)
		{
			cout << "write the new rate:" << endl;
			cin >> newrate;
			((Provider*)providerRepository.GetEntity()[i])->rate = newrate;
		}
	}
}
void Command::rewrite(string name, string surname)
{
	int m = 0;
	for (int i = 0;i < clientRepository.GetEntity().size();i++)
	{
		if ((name == ((Client*)clientRepository.GetEntity()[i])->getname() && 
			(surname == ((Client*)clientRepository.GetEntity()[i])->getsurname())))
		{
			((Client*)clientRepository.GetEntity()[i])->setdiscount(((Client*)clientRepository.GetEntity()[i])->getdiscount() + 1);
			m++;
		}
	}
	if (m == 0)
	{
		Client* cl = new Client(name, surname, 1);
		//myClient.push_back(cl);
		AddClient(*cl);
	}
	ofstream str;
	str.open("Client.txt");
	for (int i = 0;i < clientRepository.GetEntity().size();i++)
	{
		str << ((Client*)clientRepository.GetEntity()[i])->getname()<<" "
			<< ((Client*)clientRepository.GetEntity()[i])->getsurname()
			<<" " << ((Client*)clientRepository.GetEntity()[i])->getdiscount() << endl;
	}
	str.close();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Command::ChangeRating()
{
	int rate;
	string lastname;
	cout  << "you choose to change rating of restaurant:" << endl;
	cout << "type the name:" << endl;
	cin >> lastname;
	for (int i = 0;i < restaurantRepository.GetEntity().size();i++)
	{
		if (((Restaurant*)restaurantRepository.GetEntity()[i])->name == lastname)
		{
			cout << "how many points do you want to put?" << endl;
			cin >> rate;
			if (rate < 0 && rate < 6)
				break;
			((Restaurant*)restaurantRepository.GetEntity()[i])->rating = rate;
			break;
			
		}
	}
}

void Command::Order()
{
	string firstname;

	cout << "Welcome,here you can to order a table!" << endl;
	cout << "type the restaurant name:";
	cin >> firstname;
	for (int i = 0;i < estab.size();i++)
	{
		if (firstname == estab[i]->name)
		{
			estab.erase(estab.begin() + i);//erase the i-th element
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

/*void Command::AddRestaurant()
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
}*/

void Command::ShowHighRating()
{
	int max = ((Restaurant*)restaurantRepository.GetEntity()[0])->rating;
	int index = 0;
	for (int i = 1;i <restaurantRepository.GetEntity().size();i++)
	{
		if (max < ((Restaurant*)restaurantRepository.GetEntity()[i])->rating)
		{
			max = ((Restaurant*)restaurantRepository.GetEntity()[i])->rating;
			index = i;
		}
	} 
	cout << endl;
	cout << "info about restaurant with highest rating:" << endl;
	((Restaurant*)restaurantRepository.GetEntity()[index])->Write();
}

void Command::ShowLowPrice()
{
	int min = ((Restaurant*)restaurantRepository.GetEntity()[0])->price;
	int index = 0;
	for (int i = 1;i < restaurantRepository.GetEntity().size();i++)
	{
		if (min > ((Restaurant*)restaurantRepository.GetEntity()[i])->price)
		{
			min = ((Restaurant*)restaurantRepository.GetEntity()[i])->price;
			index = i;
		}
	}
	cout << endl;
	cout << "info about restaurnt with average the lowest price:" << endl;
	((Restaurant*)restaurantRepository.GetEntity()[index])->Write();
}

Command::~Command()
{
	for (int i = 0;i < pers.size();i++)
	{
		delete pers[i];
	}

	for (int i = 0;i < estab.size();i++)
	{
		delete estab[i];
	}
}