#ifndef FOOD_H_
#define FOOD_H_

#include "Item.h"
/**
* Food is a special item. What makes it special is that it may require
* cooling (in summer) during transport.
*/
class Food: public Item {
private:

	bool needsCooling;

public:

	/**
	* Creates a new food item with the given properties.
	*/
	Food(std::string name, std::string shop, std::time_t until,
	bool needsCooling);
	bool getNeedsCooling() const;
	/**
	* Returns a set containing a string that indicates the requirement
	* for cooling during transport if the "needsCooling" flag is set.
	*/
	std::set<std::string> getNotes() const;
	/**
	* Calls the base class's toString() method and returns the result.
	* If needsCooling is set, appends " [Keep cool!]" before returning
	* the result.
	*/
	virtual std::string toString() const;
	/**
	* Writes to the given ostream the string "Food;" and then
	* all attributes separated by semicolon and a final newline.
	* Example: Item;Steak;Butcher;6597989;true
	*/
	virtual void save(std::ostream& to) const;
	/**
	* Creates a new instance on the heap, using the values from
	* the given string. The string must have the format used by
	* method save. If the string does not start with "Food;", a
	* nullptr is returned. (Use function splitAt in main for the
	* implementation.)
	*/
	static Food* restore(std::string line);

};

#endif /* FOOD_H_ */
