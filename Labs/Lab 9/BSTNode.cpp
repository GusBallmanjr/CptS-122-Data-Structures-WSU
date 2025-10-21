#include "BSTNode.hpp"

BSTNode::BSTNode()
{
	data = "";
	pLeft = pRight = nullptr;
}

BSTNode::BSTNode(std::string newData)
{
	data = newData;
	pLeft = pRight = nullptr;
}

BSTNode::~BSTNode()
{
}

std::string BSTNode::getData() const
{
	return data;
}

BSTNode* BSTNode::getLeft() const
{
	return pLeft;
}

BSTNode* BSTNode::getRight() const
{
	return pRight;
}

void BSTNode::setData(std::string const nData)
{
	data = nData;
}

void BSTNode::setLeft(BSTNode* npLeft)
{
	pLeft = npLeft;
}

void BSTNode::setRight(BSTNode* npRight)
{
	pRight = npRight;
}

std::ostream& operator<<(std::ostream& rhs, BSTNode& lhs)
{
	rhs << lhs.getData() << std::endl;
	return rhs;
}