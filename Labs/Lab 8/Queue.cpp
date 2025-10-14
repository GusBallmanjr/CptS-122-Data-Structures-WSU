#include "Queue.hpp"

Queue::Queue()
{
	headPtr = tailPtr = nullptr;
}

Node* Queue::getHeadPtr() const
{
	return headPtr;
}

Node* Queue::getTailPtr() const
{
	return tailPtr;
}

void Queue::setHeadPtr(Node* const nHeadPtr)
{
	headPtr = nHeadPtr;
}

void Queue::setTailPtr(Node* const nTailPtr)
{
	tailPtr = nTailPtr;
}

bool Queue::isEmpty()
{
	if (headPtr == nullptr) // Empty
	{
		return true;
	}
	else // Not empty
	{
		return false;
	}
}

bool Queue::enqueue(std::string newData)
{
	if (tailPtr == nullptr)
	{
		tailPtr = new(Node);
		if (tailPtr != nullptr)
		{
			tailPtr->setData(newData);
			tailPtr->setNext(nullptr);
			if (headPtr == nullptr)
			{
				headPtr = tailPtr;
			}
			return true;
		}
		else return false;
	}
	else
	{
		tailPtr->setNext(new(Node));
		if (tailPtr->getNext() != nullptr)
		{
			tailPtr->getNext()->setData(newData);
			tailPtr->getNext()->setNext(nullptr);
			tailPtr = tailPtr->getNext();
			if (headPtr == nullptr)
			{
				headPtr = tailPtr;
			}
			return true;
		}
		else return false;
	}
}

std::string Queue::dequeue()
{
	Node* pCur = headPtr;
	std::string data;

	if (tailPtr != headPtr)
	{
		headPtr = pCur->getNext();
		data = pCur->getData();
		delete pCur;
	}
	else
	{
		headPtr = pCur->getNext();
		tailPtr = headPtr;
		data = pCur->getData();
		delete pCur;
	}

	return data;
}

void Queue::destroyQueue()
{
	while (headPtr != nullptr && tailPtr != nullptr)
	{
		dequeue();
	}
}

void Queue::printQueue(Node* pCur)
{
	std::cout << pCur->getData() << std::endl;
	if (pCur->getNext() != nullptr)	printQueue(pCur->getNext());
}

Queue::~Queue()
{
	destroyQueue();
}