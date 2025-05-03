#ifndef SHOPPINGLIST_H_
#define SHOPPINGLIST_H_

#include <string>
#include <memory>
#include <vector>
#include <map>
#include "Item.h"

class ShoppingList {
private:

	std::map<std::string, std::vector<std::unique_ptr<Item>>> items;

public:
	/**
	* Adds the given item to the shopping list. The item must
	* have been allocated on the heap. The shopping list is
	* responsible for removing it from the heap when it goes
	* out of existence.
	*/
	ShoppingList& operator+= (Item* item);
	/**
	* Print all items from the shopping list which must be bought
	* until the given time. The output is grouped by shops. At the
	* end of the output all collected notes from the items are
	* printed. Identical notes are printed only once. Example:
	*
	* Shopping List:
	* * Butcher:
	* - Steak (Butcher) [Keep cool!]
	*
	* * Drug store:
	*
	* * Super market:
	* - Milk (Super market) [Keep cool!]
	* - Rice (Super market)
	*
	* Notes:
	* [1] One or more items require cooling!
	*/
	void print(std::time_t until) const;
	/**
	* Writes to the given ostream all items by invoking their
	* save method.
	*/
	void save(std::ostream& to) const;
	/**
	* Reads from the given istream all items by invoking the
	* different types' restore methods until a valid pointer
	* to an object (not a nullptr) is returned.
	*/
	void load(std::istream& from);
};
#endif /* SHOPPINGLIST_H_ */
