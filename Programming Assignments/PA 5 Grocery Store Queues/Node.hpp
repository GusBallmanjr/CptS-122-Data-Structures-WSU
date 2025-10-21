#pragma once
#include "Data.hpp"

class Node
{
public:
	Node();
	~Node();

	Data* getPData() const;
	Node* getNext() const;

	void setPData(Data* const npData);
	void setNext(Node* npNext);

private:
	Data* pData;
	Node* pNext;
};


