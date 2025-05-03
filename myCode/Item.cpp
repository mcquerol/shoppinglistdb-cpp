/*
 * Item.cpp
 *
 *  Created on: 2 May 2025
 *      Author: Mateo C. Querol
 */

#include "Item.h"

Item::Item(std::string name, std::string shop, std::time_t until)
{

}

Item::~Item()
{
}

std::string Item::getName() const
{

}

std::string Item::getShop() const
{
}

std::time_t Item::getUntil() const
{

}

std::set<std::string> Item::getNotes() const
{

}

std::string Item::toString() const
{

}

void Item::save(std::ostream &to) const
{

}

Item* Item::restore(std::string line)
{

}

std::ostream& operator <<(std::ostream &lhs, const Item &item)
{

}
