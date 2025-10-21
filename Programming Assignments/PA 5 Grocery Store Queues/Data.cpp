#include "Data.hpp"

Data::Data()
{
	customerNumber = serviceTime = totalTime = 0;
	pGrocery = nullptr;
}

Data::Data(int newCustomerNumber, int newServiceTime, int newTotalTime)
{
	customerNumber = newCustomerNumber;
	serviceTime = newServiceTime;
	totalTime = newTotalTime;
	setGrocery(serviceTime);
}

Data::~Data()
{
}

int Data::getCustomer() const
{
	return customerNumber;
}

int Data::getService() const
{
	return serviceTime;
}

int Data::getTotal() const
{
	return totalTime;
}

GroceryList* Data::getGrocery() const
{
	return pGrocery;
}

void Data::setCustomer(const int newCustomer)
{
	customerNumber = newCustomer;
}

void Data::setService(const int newService)
{
	serviceTime = newService;
}

void Data::setTotal(const int newTotal)
{
	totalTime = newTotal;
}

void Data::setGrocery(const int numberOfItems)
{
	int num = (rand() % 8) + 1;
	pGrocery = new GroceryList(num);
	GroceryList* pCur = pGrocery;
	for (int i = 0; i < (numberOfItems - 1); ++i)
	{
		num = (rand() % 8) + 1;
		pCur->setpNext(new GroceryList(num));
		pCur = pCur->getPNext();
	}
}

void Data::setData(Data const nData)
{
	setCustomer(nData.getCustomer());
	setService(nData.getService());
	setTotal(getTotal() + nData.getTotal());
}

Data Data::getData()
{
	Data d1(getCustomer(), getService(), getTotal());
	return d1;
}

void Data::printGrocery()
{
	GroceryList* pCur = pGrocery;
	while (pCur != nullptr)
	{
		std::cout << pCur->getGrocery();
		if (pCur->getPNext() != nullptr)
		{
			std::cout << " & ";
		}
		else
		{
			std::cout << std::endl;
		}
		pCur = pCur->getPNext();
	}
}

std::ostream& operator<<(std::ostream& lhs, Data rhs)
{
	if (rhs.getTotal() != -1)
	{
		lhs << "Customer Number: " << rhs.getCustomer() << "\t Service Time: " << rhs.getService() << "\t Total Time: " << rhs.getTotal() << "\t";
		rhs.printGrocery();
	}
	else
	{
		lhs << "Customer Number: " << rhs.getCustomer() << "\t Service Time: " << rhs.getService() << "\t Total Time: Unknown at this time." << "\t";
		rhs.printGrocery();
	}
	return lhs;
}
