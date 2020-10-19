#include<iostream>
#include<fstream>
using namespace std;
#include"Command.h"
#include"Repository.h"
#include"StaffRepository.h"

StaffRepository::StaffRepository(bool sync) : Repository(sync)
{
	ReadFromStorage();
}

bool StaffRepository::Add(Staff& staff)
{
	return Repository::Add(&staff);
}

void StaffRepository::ReadFromStorage()
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
			Staff* s = new Staff(name, position, experience, rating);
			Add(*s);
		}
	}
	fin.close();
}

void StaffRepository::WriteToStorage()
{
	ofstream fout("Staff.txt");
	for (int i = 0;i < vEntity.size();i++)
	{
		fout << ((Staff*)vEntity[i])->getname() << " " << ((Staff*)vEntity[i])->getposition() << " "
			<< ((Staff*)vEntity[i])->getexperience() << " " << ((Staff*)vEntity[i])->getrating() << endl;
	}
	fout.close();
}