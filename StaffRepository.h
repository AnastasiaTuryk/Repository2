#ifndef STAFFREPOSITORY_H
#define STAFFREPOSITORY_H
#include <fstream>


#include "Repository.h"
#include"Staff.h"

class StaffRepository : public Repository
{
public:

	StaffRepository(bool sync = false);
	~StaffRepository() {}
	bool Add(Staff& staff);
	void ReadFromStorage();
	void WriteToStorage();
};
#endif // 
