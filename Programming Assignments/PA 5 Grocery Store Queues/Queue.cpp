#include "Queue.hpp"

Queue::Queue()
{
	headPtr = tailPtr = nullptr;
}

Queue::~Queue()
{
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

void Queue::setTailPtr(Node* const ntailPtr)
{
	tailPtr = ntailPtr;
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

bool Queue::enqueue(Data newData)
{
	if (tailPtr == nullptr)
	{
		tailPtr = new(Node);
		if (tailPtr != nullptr)
		{
			tailPtr->getPData()->setData(newData);
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
			tailPtr->getNext()->getPData()->setData(newData);
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

Data Queue::dequeue()
{
	Node* pCur = headPtr;
	Data data;

	if (tailPtr != headPtr)
	{
		headPtr = pCur->getNext();
		data = pCur->getPData()->getData();
		delete pCur;
	}
	else
	{
		headPtr = pCur->getNext();
		tailPtr = headPtr;
		data = pCur->getPData()->getData();
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
	std::cout << "Queue Status: ";
	if (pCur != nullptr)
	{
		std::cout << pCur->getPData()->getData() << std::endl;
		if (pCur->getNext() != nullptr)
		{
			printQueue(pCur->getNext());
		}
		else 
		{ 
			pCur->getPData()->printGrocery(); 
		}
	}
	else
	{
		std::cout << "Queue is empty." << std::endl;
	}
}