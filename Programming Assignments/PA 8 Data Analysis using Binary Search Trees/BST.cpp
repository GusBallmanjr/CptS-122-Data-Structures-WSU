#include "BST.hpp"

BST::BST()
{
	pRoot = nullptr;
}

BST::~BST()
{
	if (pRoot != nullptr) destroyTree(pRoot);
}

void BST::insert(std::string const newData, int const newUnits)
{
	if (pRoot != nullptr) insert(newData, newUnits, pRoot);
	else
	{
		pRoot = new TransactionNode(newData, newUnits);
	}
}

void BST::inOrderTraversal()
{
	if (pRoot != nullptr) inOrderTraversal(pRoot);
}

int BST::findSmallest()
{
	int min = findLargest();
	if (pRoot != nullptr)
	{
		min = dynamic_cast<TransactionNode*>(pRoot)->getUnits();
		min = findSmallest(pRoot, min);
	}
	return min;
}

int BST::findLargest()
{
	int max = 0;
	if (pRoot != nullptr) max = findLargest(pRoot, max);
	return max;
}

std::string BST::findData(int const findUnits)
{
	std::string type;
	if (pRoot != nullptr)
	{
		if (dynamic_cast<TransactionNode*> (pRoot)->getUnits() == findUnits)
		{
			return pRoot->getData();
		}
		else
		{
			type = findData(findUnits, pRoot, type);
			return type;
		}
	}
}

void BST::destroyTree(Node* pCur)
{
	if (pCur == nullptr) return;
	destroyTree(pCur->getLeft());
	destroyTree(pCur->getRight());
	delete pCur;
}

void BST::insert(std::string const newData, int const newUnits, Node* pCur)
{
	if (newUnits < dynamic_cast<TransactionNode*> (pCur)->getUnits()) // go left
	{
		if (pCur->getLeft() == nullptr) // insert
		{
			pCur->setLeft(new TransactionNode(newData, newUnits));
		}
		else
		{
			insert(newData, newUnits, pCur->getLeft());
		}
	}
	else if (newUnits > dynamic_cast<TransactionNode*> (pCur)->getUnits()) // Go Right
	{
		if (pCur->getRight() == nullptr)
		{
			pCur->setRight(new TransactionNode(newData, newUnits));
		}
		else
		{
			insert(newData, newUnits, pCur->getRight());
		}
	}
}

void BST::inOrderTraversal(Node* pCur)
{
	if (pCur == nullptr) return;
	inOrderTraversal(pCur->getLeft());
	pCur->printData();
	inOrderTraversal(pCur->getRight());
}

int BST::findLargest(Node* pCur, int max)
{
	if (pCur->getRight() == nullptr)
	{
		max = dynamic_cast<TransactionNode*>(pCur)->getUnits();
	}
	else
	{
		max = findLargest(pCur->getRight(), max);
	}
	return max;
}

int BST::findSmallest(Node* pCur, int min)
{
	if (pCur->getLeft() == nullptr)
	{
		min = dynamic_cast<TransactionNode*>(pCur)->getUnits();
	}
	else
	{
	min = findSmallest(pCur->getLeft(), min);
	}
	return min;
}

std::string BST::findData(int const findUnits, Node* pCur, std::string type)
{
	if (pCur == nullptr)
	{
		return "";
	}
	std::string result = findData(findUnits, pCur->getLeft(), type);
	if (result != "")
	{
		return result;
	}
	if (findUnits == dynamic_cast<TransactionNode*> (pCur)->getUnits())
	{
		return pCur->getData();
	}
	result = findData(findUnits, pCur->getRight(), type);
	return result;
}
