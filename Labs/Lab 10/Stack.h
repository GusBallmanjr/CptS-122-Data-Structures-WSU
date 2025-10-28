#pragma once

#include <iostream>
#include <string>

template <typename T>
class Stack
{
public:	
	Stack(int newSize) { size = newSize; }
	~Stack();

	bool push(T& newItem);
	bool pop(T& popItem);
	bool peek(T& item);

	bool isEmpty();
	T postFix(std::string str)
private:
	int size, maxSize;
	T* pTop;
	T evaluatePost(std::string str);
};

template <typename T>
Stack<T>::~Stack()
{
	while (pTOp != nullptr)
	{
		delete pTop;
		pTop--;
	}
}

template <typename T>
bool Stack<T>::push(T& newItem)
{
	*(pTop + 1) = new T;
	if (*(pTop + 1) != nullptr)
	{
		*(pTop + 1) = newItem;
		pTop++
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
bool Stack<T>::pop(T& popItem)
{
	T* pCur = pTop;
	popItem = *pTop;
	pTop = pTop - 1;
	delete pCur;
	if (pCur != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
bool Stack<T>::peek(T& item)
{
	if (pTop != nullptr)
	{
		item = *pTop;
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
bool Stack<T>::isEmpty()
{
	if (pTop == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
inline T Stack<T>::evaluatePost(std::string str)
{
	T total = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '+')
		{
			for (int j = 0; j < i; j++)
			{
				total += (T)str[j];
			}
		}
		else if (str[i] == '-')
		{
			for (int j = 0; j < i; j++)
			{
				total -= (T)str[j];
			}
		}
		else if (str[i] == '*')
		{
			for (int j = 0; j < i; j++)
			{
				total *= (T)str[j];
			}
		}
		else if (str[i] == '/')
		{
			for (int j = 0; j < i; j++)
			{
				total /= (T)str[j];
			}
		}
		else if (str[i] = '%')
		{
			for (int j = 0; j < i; j++)
			{
				total %= (T)str[j];
			}
		}
	}
	return total;
}

template <typename T>
T Stack<T>::postFix(std::string str)
{
	std::string postFixStr = "";
	T popItem;
	int plus = 0, minus = 0, multiply = 0, divide = 0, modulus = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '+')
		{
			plus++;
			if (isEmpty() == false)
			{
				pop(popItem);
				postFixStr += popItem;
			}
			minus = modulus = multiply = divide = 0;
			if (plus == 1)
			{
				push((T)str[i]);
			}
		}
		if (str[i] == '/')
		{
			divide++;
			if (isEmpty() == false)
			{
				pop(popItem);
				postFixStr += popItem;
			}
			minus = modulus = multiply = plus = 0;
			if (divide == 1)
			{
				push((T)str[i]);
			}
		}
		if (str[i] == '*')
		{
			multiply++;
			if (isEmpty() == false)
			{
				pop(popItem);
				postFixStr += popItem;
			}
			minus = modulus = divide = plus = 0;
			if (multiply == 1)
			{
				push((T)str[i]);
			}
		}
		if (str[i] = '%')
		{
			modulus++;
			if (isEmpty() == false)
			{
				pop(popItem);
				postFixStr += popItem;
			}
			minus = multiply = divide = plus = 0;
			if (modulus == 1)
			{
				push((T)str[i]);
			}
		}
		if (str[i] == '-')
		{
			minus++;
			if (isEmpty() == false)
			{
				pop(popItem);
				postFixStr += popItem;
			}
			modulus = multiply = divide = plus = 0;
			if (minus == 1)
			{
				push((T)str[i]);
			}
		}
		else
		{
			postFixStr += str[i];
		}
	}
	return evaluatePost(postFixStr);
}