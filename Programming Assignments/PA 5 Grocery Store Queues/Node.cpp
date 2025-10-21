#include "Node.hpp"

Node::Node()
{
	pData = new(Data);
	pNext = nullptr;
}

Node::~Node()
{
}

Data* Node::getPData() const
{
	return pData;
}

Node* Node::getNext() const
{
	return pNext;
}

void Node::setPData(Data* const npData)
{
	pData = npData;
}

void Node::setNext(Node* npNext)
{
	pNext = npNext;
}