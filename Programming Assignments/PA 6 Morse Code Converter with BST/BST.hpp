#pragma once
#include <iostream>
#include <string>
#include "BSTNode.hpp"

template <typename T, typename C>
class BST
{
public:
	BST();

	BSTNode<T,C>* getPRoot() const;

	void setPRoot(BSTNode<T,C>* const npRoot);

	void insert(C Plaindata, T data);
	T inOrderTraversal(C lookUpData);
private:
	BSTNode<T, C>* pRoot;
	void insert(C Plaindata, T data, BSTNode<T, C>* pCur);
	T inOrderTraversal(BSTNode<T, C>* pCur, C lookUpData);
};

template <typename T, typename C>
inline BST<T,C>::BST()
{
	pRoot = nullptr;
}

template <typename T, typename C>
inline BSTNode<T, C>* BST<T,C>::getPRoot() const
{
	return pRoot;
}

template <typename T, typename C>
inline void BST<T,C>::setPRoot(BSTNode<T, C>* const npRoot)
{
	pRoot = npRoot;
}

template <typename T, typename C>
inline void BST<T,C>::insert(C Plaindata, T data)
{
	if (pRoot == nullptr)
	{
		pRoot = new BSTNode<T,C>(Plaindata, data);
	}
	else
	{
		insert(Plaindata, data, pRoot);
	}
}

template<typename T, typename C>
inline T BST<T, C>::inOrderTraversal(C lookUpData)
{
	return inOrderTraversal(pRoot, lookUpData);
}

template <typename T, typename C>
inline void BST<T,C>::insert(C Plaindata, T data, BSTNode<T, C>* pCur)
{
	if (Plaindata < pCur->getPlain()) // go left
	{
		if (pCur->getPLeft() != nullptr)
		{
			pCur = pCur->getPLeft();
			insert(Plaindata, data, pCur);
		}
		else
		{
			pCur->setPLeft(new BSTNode<T, C>(Plaindata, data));
		}
	}
	else if (Plaindata > pCur->getPlain()) // go right
	{
		if (pCur->getPRight() != nullptr)
		{
			pCur = pCur->getPRight();
			insert(Plaindata, data, pCur);
		}
		else
		{
			pCur->setPRight(new BSTNode<T,C>(Plaindata, data));
		}
	}
}

template <typename T, typename C>
inline T BST<T,C>::inOrderTraversal(BSTNode<T,C>* pCur, C lookUpData)
{
	std::string morse = "";
	if (pCur != nullptr)
	{
		morse = inOrderTraversal(pCur->getPLeft(), lookUpData);
		if (morse != "")
		{ 
			return morse;
		}
		if (pCur->getPlain() == lookUpData)
		{
			return pCur->getMorse();
		}
		morse = inOrderTraversal(pCur->getPRight(), lookUpData);
		if (morse != "")
		{
			return morse;
		}
	}

	return "";
}