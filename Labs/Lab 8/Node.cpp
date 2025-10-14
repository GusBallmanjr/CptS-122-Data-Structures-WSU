#include "Node.hpp"

Node::Node()
{
	data = "";
	pNext = nullptr;
}

Node::~Node()
{
}

std::string Node::getData() const
{
	return data;
}

Node* Node::getNext() const
{
	return pNext;
}

void Node::setData(std::string const ndata)
{
	data = ndata;
}

void Node::setNext(Node* npNext)
{
	pNext = npNext;
}