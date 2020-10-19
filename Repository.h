#ifndef REPOSITORY_H
#define REPOSITORY_H

#include"Entity.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Repository
{
protected:
	vector <Entity*> vEntity;
	bool sync;
	bool Add(Entity*);
	virtual void ReadFromStorage() {}
	virtual void WriteToStorage() {}


public:
	vector <Entity*> GetEntity()
	{
		return vEntity;
	}
	Repository(bool sync = false);
	~Repository();
	void cleartheindex(int data)
	{
		vEntity.erase(vEntity.begin() + data);
	}
};
#endif // !REPOSITORY_H

