// Standard (system) header files
#include <iostream>
#include <stdlib.h>
#include <fstream>

// Add your project's header files here
#include "ShoppingList.h"
#include "Food.h"

using namespace std;

/**
* Splits the string in parameter remainder at the first occurrence
* of the character in parameter separator. Changes remainder to
* contain only the part after the separator and returns the part
* before the separator.
*
* If the separator is not found, returns the string in parameter
* remainder and sets the parameter remainder to the empty string.
*/
string splitAt(string& remainder, char separator) {
	string::size_type pos = remainder.find(separator);
	if (pos == string::npos) {
		string result = remainder;
		remainder.clear();
		return result;
	}
	string result = remainder.substr(0, pos);
	remainder = remainder.substr(pos + 1);
	return result;
}
// Main program
int main (void) {
	ShoppingList list;
	time_t inTwoDays = time(nullptr) + 2 * 24 * 3600;
	time_t inThreeDays = time(nullptr) + 3 * 24 * 3600;

	list += new Item("Paper tissues", "Super market", inThreeDays);
	list += new Food("Milk", "Super market", inTwoDays, true);
	list += new Food("Rice", "Super market", inTwoDays, false);
	list += new Food("Steak", "Butcher", inTwoDays, true);
	list += new Item("Shampoo", "Drug store", inThreeDays);
	list += new Item("Washing powder", "Drug store", inThreeDays);

	list.print(inTwoDays);
	ofstream out("data.txt");
	list.save(out);
	out.close();
	ShoppingList reloaded;
	ifstream in("data.txt");
	reloaded.load(in);
	reloaded.print(inThreeDays);
	return 0;
}
