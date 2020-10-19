#include<iostream>
#include<fstream>
using namespace std;
#include"Command.h"
#include"Repository.h"
#include"ProviderRepository.h"

ProviderRepository::ProviderRepository(bool sync) : Repository(sync)
{
	ReadFromStorage();
}

bool ProviderRepository::Add(Provider& provider)
{
	return Repository::Add(&provider);
}

void ProviderRepository::ReadFromStorage()
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
			Provider* pr = new Provider(name, rate, country);
			Add(*pr);
		}
	}
	fin.close();
}

void ProviderRepository::WriteToStorage()
{
	ofstream str;
	str.open("Provider.txt");
	for (int i = 0;i < vEntity.size();i++)
	{
		str << ((Provider*)vEntity[i])->getname()<<" "<<((Provider*)vEntity[i])->getrating()<<
			" "<<((Provider*)vEntity[i])->getcountry() << endl;
	}
	str.close();
}
