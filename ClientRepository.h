#ifndef CLIENTREPOSITORY_H
#define CLIENTREPOSITORY_H
#include <fstream>


#include "Repository.h"
#include"Client.h"

class ClientRepository : public Repository
{
public:

	ClientRepository(bool sync = false);
	~ClientRepository() {}
	bool Add(Client& client);
	void ReadFromStorage();
	void WriteToStorage();
};
#endif // !CLIENTREPOSITORY_H
