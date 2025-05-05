#include <iostream>
#include "ShoppingList.h"
#include "Food.h"

using namespace std;

// Task 5: Provide implementation of operator += (3 points)
ShoppingList& ShoppingList::operator +=(Item *item)
{
	items[item->getShop()].emplace_back(std::unique_ptr<Item>(item));
	return *this;
}

// Task 6: Provide implementation of print (15 points)
// Hint: use a set to collect all notes from the various items
// and print its content at the end.
void ShoppingList::print(time_t until) const
{
	auto notesSet = set<string>();
	int noteNum = 0;

	cout << "Shopping List: " << endl;
	for(const auto& item: items)
	{
		cout << item.first << ":" << endl;
		for(const auto& vec : item.second)
		{
			if(vec->getUntil() <= until)
			{
				cout << *vec << endl;
				const auto& notes = vec->getNotes();
				notesSet.insert(notes.begin(), notes.end());
			}
		}
		cout << endl;
	}

	if(!notesSet.empty())
	{
		cout << "Notes:" << endl;
		for (const auto& note : notesSet)
		{
		    cout << "[" << ++noteNum << "] " << note << "\n";
		}
	}
}

// Task 7: Provide implementation of save (3 points)
void ShoppingList::save(std::ostream& to) const
{
	for(const auto& item : items)
	{
		for(const auto& vec : item.second)
		{
			vec->save(to);
		}
	}
}

// Task 8: Provide implementation of load (10 points)
void ShoppingList::load(std::istream &from)
{

}
