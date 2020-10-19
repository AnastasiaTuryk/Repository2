#include<iostream>
#include<fstream>
using namespace std;
#include"Repository.h"
#include"RestaurantRepository.h"

RestaurantRepository::RestaurantRepository(bool sync): Repository(sync)
{
	ReadFromStorage();
}

bool RestaurantRepository::Add(Restaurant& restaurant)
{
	return Repository::Add(&restaurant);
}

void RestaurantRepository::ReadFromStorage()
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
	while (fin)
	{
		if (fin >> name >> design >> kitchen >> rating >> price)
		{
			Restaurant* r = new Restaurant(name, design, kitchen, rating, price);
			Add(*r);
		}
	}
	fin.close();
}

void RestaurantRepository::WriteToStorage()
{
	ofstream fout("Restaurant.txt");
	for (int i = 0;i < vEntity.size();i++)
	{
		fout << ((Restaurant*)vEntity[i])->getname() << " "
			<< ((Restaurant*)vEntity[i])->getdesign() << " "
			<< ((Restaurant*)vEntity[i])->getkitchen() << " " 
			<< ((Restaurant*)vEntity[i])->getrating() << " "
			<< ((Restaurant*)vEntity[i])->getprice()<<endl;
	}
	fout.close();
}

