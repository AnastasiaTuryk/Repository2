#include "Repository.h"
Repository::Repository(bool sync)
{
	this->sync = sync;
	ReadFromStorage();
}

Repository::~Repository()
{
	WriteToStorage();
}

bool Repository::Add(Entity* entity)
{
	vEntity.push_back(entity);
	if (sync)
		WriteToStorage();
	return true;
}