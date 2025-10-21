#include "GroceryList.hpp"

GroceryList::GroceryList()
{
	pNext = nullptr;
	grocery = "";
}

GroceryList::GroceryList(int num)
{
	pNext = nullptr;
	
	switch (num)
	{
	case 1: grocery = "Milk";
		break;
	case 2: grocery = "Eggs";
		break;
	case 3: grocery = "Chicken";
		break;
	case 4: grocery = "Noodles";
		break;
	case 5: grocery = "Lactose Free Fat Free Ultra Patronized Milk";
		break;
	case 6: grocery = "Carrots";
		break;
	case 7: grocery = "Coffee";
		break;
	case 8: grocery = "ToothPaste";
		break;
	}
}

GroceryList::~GroceryList() {}

GroceryList* GroceryList::getPNext() const
{
	return pNext;
}

std::string GroceryList::getGrocery() const
{
	return grocery;
}

void GroceryList::setpNext(GroceryList* const npNext)
{
	pNext = npNext;
}

void GroceryList::setGrocery(std::string const nGrocery)
{
	grocery = nGrocery;
}
