#pragma once
#include "ListNode.hpp"

template <typename T>
class List
{
public:
	List();
	~List();

	ListNode<T>* getHeadPtr() const;
	void setHeadPtr(ListNode<T>* newHeadPtr);

	bool insertNode(T newData);

	void destroyList();
private:
	ListNode<T>* HeadPtr;
	void destroyList(ListNode<T>* pCur);
};

template<typename T>
inline List<T>::List()
{
	HeadPtr = nullptr;
}

template<typename T>
inline List<T>::~List()
{
	destroyList();
}

template<typename T>
inline ListNode<T>* List<T>::getHeadPtr() const
{
	return HeadPtr;
}

template<typename T>
inline void List<T>::setHeadPtr(ListNode<T>* newHeadPtr)
{
	HeadPtr = newHeadPtr;
}

template<typename T>
inline bool List<T>::insertNode(T newData)
{
	ListNode<T>* pCur = new ListNode<T>;
	if (pCur != nullptr)
	{
		pCur->setData(newData);
		pCur->setNext(HeadPtr);
		HeadPtr = pCur;
		return true;
	}
	return false;

}

template<typename T>
inline void List<T>::destroyList()
{
	destroyList(HeadPtr);
}

template<typename T>
inline void List<T>::destroyList(ListNode<T>* pCur)
{
	if (pCur->getNext() != nullptr)
	{
		destroyList(pCur->getNext());
		delete pCur;
	}
	else
	{
		delete pCur;
	}
}
