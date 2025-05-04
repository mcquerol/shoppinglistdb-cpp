#include <string>
#include "Food.h"

using namespace std;

// Task 1: Provide constructor implementation (2 points)
Food::Food(string name, string shop, time_t until, bool needsCooling) : name{name}, shop{shop}, until{until}, needsCooling{needsCooling}
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

// Task 2: Provide toString implementation (4 points)
string Food::toString() const
{
	return Item::toString() + (needsCooling ? " [Keep Cool!]" : "");
}

// Task 3: Provide implementation of save (5 points)
void Food::save(ostream& to) const
{

}

// Task 4: Provide implementation of restore (8 points)
Food* Food::restore(string line)
{
	extern string splitAt(string& remainder, char separator);
}
