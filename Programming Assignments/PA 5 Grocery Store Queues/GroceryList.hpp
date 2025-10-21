#pragma once

#include <iostream>
#include <string>

class GroceryList
{
public:
	GroceryList();
	GroceryList(int num);
	~GroceryList();
	
	GroceryList* getPNext() const;
	std::string getGrocery() const;

	void setpNext(GroceryList* const npNext);
	void setGrocery(std::string const nGrocery);

private:
	GroceryList* pNext;
	std::string grocery;
};