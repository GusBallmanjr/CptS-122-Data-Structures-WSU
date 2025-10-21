#pragma once
#include "Node.hpp"


class Queue
{
public:
	Queue();
	~Queue();

	Node* getHeadPtr() const;
	Node* getTailPtr() const;

	void setHeadPtr(Node* const nHeadPtr);
	void setTailPtr(Node* const ntailPtr);

	bool isEmpty();
	bool enqueue(Data newData);
	Data dequeue();
	void destroyQueue();
	void printQueue(Node* pCur);

private:
	Node* headPtr, * tailPtr;
};