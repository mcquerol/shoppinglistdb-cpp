#ifndef ITEM_H_
#define ITEM_H_

#include <ctime>
#include <string>
#include <set>
#include <ostream>
/**
* A shopping list item. Items have a name, they must be bought at
* a particular shop (bread at the bakery, meat from a butcher etc.),
* and they are required until a particular date/time. (In reality, some
* items can be bought at several places --meat from the butcher or from
* the super market-- but this isn't modelled here.)
*/
class Item {
private:
	std::string name;
	std::string shop;
	std::time_t until;
public:
	/**
	* Create a new item with the given properties.
	*/
	Item(std::string name, std::string shop, std::time_t until);
	virtual ~Item();
	std::string getName() const;
	std::string getShop() const;
	std::time_t getUntil() const;
	/**
	* Special kinds of items (see class Food) may require one or more
	* notes to be appended to the shopping list. This function returns
	* the notes required by an item.
	*/
	virtual std::set<std::string> getNotes() const;
	/**
	* Returns a string with the name of the item followed by the shop
	* in parenthesis.
	*/
	virtual std::string toString() const;
	/**
	* Writes to the given ostream the string "Item;" and then
	* all attributes separated by semicolon and a final newline.
	* Example: Item;Soap;Drug store;6597989
	*/
	virtual void save(std::ostream& to) const;
	/**
	* Creates a new instance on the heap, using the values from
	* the given string. The string must have the format used by
	* method save. If the string does not start with "Item;", a
	* nullptr is returned. (Use function splitAt in main for the
	* implementation.)
	*/
	static Item* restore(std::string line);
};

std::ostream& operator<<(std::ostream& lhs, const Item& item);

#endif /* ITEM_H_ */
