#pragma once
#include <iostream>
#include <string>

class Node
{
public:
	Node();
	~Node();

	std::string getData() const;
	Node* getNext() const;

	void setData(std::string const ndata);
	void setNext(Node* npNext);

private:
	std::string data;
	Node* pNext;
};