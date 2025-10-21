#pragma once
#include "GroceryList.hpp"

class Data
{
public:
	Data();
	Data(int newCustomerNumber, int newServiceTime, int newTotalTime);
	~Data();
	int getCustomer() const;
	int getService() const;
	int getTotal() const;
	GroceryList* getGrocery() const;

	void setCustomer(const int newCustomer);
	void setService(const int newService);
	void setTotal(const int newTotal);
	void setGrocery(const int numberOfItems);

	void setData(Data const nData);
	Data getData();

	void printGrocery();

private:
	int customerNumber; 
	int serviceTime;
	int totalTime;
	GroceryList* pGrocery;
};

std::ostream& operator<<(std::ostream& lhs, Data rhs);