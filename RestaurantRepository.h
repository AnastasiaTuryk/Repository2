#ifndef RESTAURANTREPOSITORY_H
#define RESTAURANTREPOSITORY_H
#include <fstream>


#include "Repository.h"
#include"Restaurant.h"

class RestaurantRepository : public Repository
{
public:

	RestaurantRepository(bool sync = false);
	~RestaurantRepository() {}
	bool Add(Restaurant& restaurant);
	void ReadFromStorage();
	void WriteToStorage();
};
#endif // 

