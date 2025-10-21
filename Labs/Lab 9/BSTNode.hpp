#pragma once

#include <iostream>
#include <string>

class BSTNode
{
public:
	BSTNode();
	BSTNode(std::string newData);
	~BSTNode();

	std::string getData() const;
	BSTNode* getLeft() const;
	BSTNode* getRight() const;

	void setData(std::string const nData);
	void setLeft(BSTNode* const npLeft);
	void setRight(BSTNode* const npRight);
private:
	std::string data;
	BSTNode* pLeft, * pRight;
};

std::ostream& operator<<(std::ostream& rhs, BSTNode& lhs);