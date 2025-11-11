#pragma once
#include <iostream>
#include <string>

template <typename T>
class ListNode
{
public:
	ListNode();
	~ListNode();

	ListNode<T>* getNext() const;
	T& getData();

	void setNext(ListNode<T>* const newNext);
	void setData(T const newData);

private:
	ListNode<T>* pNext;
	T nodeData;
};

template <typename T>
inline ListNode<T>::ListNode()
{
	pNext = nullptr;
}

template <typename T>
inline ListNode<T>::~ListNode()
{
}

template <typename T>
inline ListNode<T>* ListNode<T>::getNext() const
{
	return pNext;
}

template<typename T>
inline T& ListNode<T>::getData()
{
	return nodeData;
}

template<typename T>
inline void ListNode<T>::setNext(ListNode* const newNext)
{
	pNext = newNext;
}

template<typename T>
inline void ListNode<T>::setData(T const newData)
{
	nodeData = newData;
}
