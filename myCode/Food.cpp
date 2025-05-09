
#include "Food.h"

#include <sstream>

using namespace std;

// Task 1: Provide constructor implementation (2 points)
Food::Food(string name, string shop, time_t until, bool needsCooling) : Item{name, shop, until}, needsCooling{needsCooling}
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
	to << "Food;" << Item::getName() << ';' << Item::getShop() << ';' << Item::getUntil() << ';' << (needsCooling ? "true" : "false") << "\n";
}

// Task 4: Provide implementation of restore (8 points)
Food* Food::restore(string line)
{
	extern string splitAt(string& remainder, char separator);
	string originalLine = line;  // keep the original string
	string type = splitAt(line, ';');
	if(type != "Food")
	{
		return nullptr;
	}
    std::string name, shop, timeStr, needsCoolingStr;
    time_t until;
    bool needsCooling;

    istringstream iss(line);

	getline(iss, name, ';');
	getline(iss, shop, ';');

	getline(iss, timeStr, ';');
	until = static_cast<time_t>(std::stol(timeStr));
	getline(iss, needsCoolingStr, ';');
	needsCooling = (needsCoolingStr == "true");

	return new Food(name,shop,until,needsCooling);

}
