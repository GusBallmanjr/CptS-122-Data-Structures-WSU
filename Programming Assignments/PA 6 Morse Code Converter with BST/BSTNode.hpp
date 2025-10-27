#pragma once

#include <iostream>
#include <string>

template <typename T, typename C>
class BSTNode
{
public:
	BSTNode();
	BSTNode(C plaindata, T data);
	T getMorse() const;
	C getPlain() const;
	BSTNode<T, C>* getPLeft() const;
	BSTNode<T, C>* getPRight() const;

	void setPLeft(BSTNode<T, C>* const npLeft);
	void setPRight(BSTNode<T, C>* const npRight);
	void setPlain(C const nPlain);
	void setMorse(T const nMorse);
private:
	C plain;
	T morse;
	BSTNode<T, C>* pLeft, * pRight;
};

template <typename T, typename C>
BSTNode<T, C>::BSTNode()
{
	plain = '\0';
	morse = "";
	pLeft = pRight = nullptr;
}

template<typename T, typename C>
inline BSTNode<T, C>::BSTNode(C Plaindata, T data)
{
	plain = Plaindata;
	morse = data;
	pLeft = pRight = nullptr;
}

template <typename T, typename C>
T BSTNode<T, C>::getMorse() const
{
	return morse;
}

template <typename T, typename C>
C BSTNode<T, C>::getPlain() const
{
	return plain;
}

template <typename T, typename C>
inline void BSTNode<T, C>::setPLeft(BSTNode<T, C>* const npLeft)
{
	pLeft = npLeft;
}

template <typename T, typename C>
inline void BSTNode<T, C>::setPRight(BSTNode<T, C>* const npRight)
{
	pRight = npRight;
}

template <typename T, typename C>
inline BSTNode<T, C>* BSTNode<T, C>::getPLeft() const
{
	return pLeft;
}

template <typename T, typename C>
inline BSTNode<T, C>* BSTNode<T, C>::getPRight() const
{
	return pRight;
}

template <typename T, typename C>
void BSTNode<T, C>::setPlain(C const nPlain)
{
	plain = nPlain;
}

template <typename T, typename C>
void BSTNode<T, C>::setMorse(T const nMorse)
{
	morse = nMorse;
}