#include <string>
#include "Food.h"

using namespace std;

// Task 1: Provide constructor implementation (2 points)
Food::Food(string name, string shop, time_t until, bool needsCooling)
{

}

bool Food::getNeedsCooling() const {
	return needsCooling;
}

set<string> Food::getNotes() const
{
	if (!needsCooling)
	{
		return set<string>();
	}
	set<string> result;
	result.insert("One or more items require cooling!");
	return result;
}

string Food::toString() const
{

}

void Food::save(ostream& to) const
{

}

Food* Food::restore(string line)
{
	extern string splitAt(string& remainder, char separator);
}
