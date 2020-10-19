
#ifndef PROVIDERREPOSITORY_H
#define PROVIDERREPOSITORY_H
#include <fstream>

#include "Repository.h"
#include"Provider.h"

class ProviderRepository : public Repository
{
public:
	ProviderRepository(bool sync = false);
	~ProviderRepository() {}
	bool Add(Provider& provider);
	void ReadFromStorage();
	void WriteToStorage();
};
#endif 