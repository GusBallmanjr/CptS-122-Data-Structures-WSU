#pragma once
#include <iostream>
#include <string>


class Node
{
public:
	Node(std::string newData)
	{
		data = newData;
		pLeft = pRight = nullptr;
	}
	virtual ~Node() {}

	std::string getData() const { return data; }
	Node* getLeft() const { return pLeft; }
	Node* getRight() const { return pRight; }

	void setData(std::string const newData) { data = newData; }
	void setLeft(Node* const newLeft) { pLeft = newLeft; }
	void setRight(Node* const newRight) { pRight = newRight; }

	virtual void printData() = 0;
protected:
	std::string data;
	Node* pLeft, * pRight;
};