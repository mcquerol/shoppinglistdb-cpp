/*
 * Item.cpp
 *
 *  Created on: 2 May 2025
 *      Author: Mateo C. Querol
 */

#include "Item.h"
#include <sstream>

using namespace std;

Item::Item(std::string name, std::string shop, std::time_t until) : name{name}, shop{shop}, until{until}
{
}

Item::~Item()
{
}

std::string Item::getName() const
{
	return name;
}

std::string Item::getShop() const
{
	return shop;
}

std::time_t Item::getUntil() const
{
	return until;
}

std::set<std::string> Item::getNotes() const
{
	return set<string>();
}

std::string Item::toString() const
{
	return "- " + name + " (" + shop + ")"; //TODO fix
}

void Item::save(std::ostream &to) const
{
	to << "Item;" << name << ';' << shop << ';' << until << "\n";
}

Item* Item::restore(std::string line)
{
    std::string name, shop, timeStr;
    time_t until;

    istringstream iss(line);

	getline(iss, name, ';');
	getline(iss, shop, ';');

	getline(iss, timeStr, ';');
	until = static_cast<time_t>(std::stol(timeStr));

	return new Item(name,shop,until);

}

std::ostream& operator <<(std::ostream &lhs, const Item &item)
{
	return lhs << item.toString();
}
