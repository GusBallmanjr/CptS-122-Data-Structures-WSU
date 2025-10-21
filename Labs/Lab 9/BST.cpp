#include "BST.hpp"

BST::BST()
{
	pRoot = nullptr;
}

BST::~BST()
{
	//destroyTree();
}

BSTNode* BST::getRoot() const
{
	return pRoot;
}

void BST::setRoot(BSTNode* const npRoot)
{
	pRoot = npRoot;
}

void BST::insertNode(std::string newData)
{
	if (pRoot == nullptr)
	{
		pRoot = new BSTNode(newData);
	}
	else
	{
		insertNode(newData, pRoot);
	}
}

void BST::inOrderTraversal()
{
	inOrderTraversal(pRoot);
}

void BST::preOrderTraversal()
{
	preOrderTraversal(pRoot);
}

void BST::postOrderTraversal()
{
	postOrderTraversal(pRoot);
}

bool BST::isEmpty()
{
	if (pRoot == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void BST::destroyTree()
{

}

void BST::insertNode(std::string newData, BSTNode* pCur)
{
	if (newData < pCur->getData()) // go left
	{
		if (pCur->getLeft() != nullptr)
		{
			pCur = pCur->getLeft();
			insertNode(newData, pCur);
		}
		else
		{
			pCur->setLeft(new BSTNode(newData));
		}
	}
	else if (newData > pCur->getData()) // go right
	{
		if (pCur->getRight() != nullptr)
		{
			pCur = pCur->getRight();
			insertNode(newData, pCur);
		}
		else
		{
			pCur->setRight(new BSTNode(newData));
		}
	}
}

void BST::inOrderTraversal(BSTNode* pCur)
{
	if (pCur == nullptr)
	{
		return;
	}
	inOrderTraversal(pCur->getLeft());
	std::cout << pCur->getData();
	inOrderTraversal(pCur->getRight());
}

void BST::preOrderTraversal(BSTNode* pCur)
{
	if (pCur == nullptr)
	{
		return;
	}
	std::cout << pCur->getData();
	preOrderTraversal(pCur->getLeft());
	preOrderTraversal(pCur->getRight());
}

void BST::postOrderTraversal(BSTNode* pCur)
{
	if (pCur == nullptr)
	{
		return;
	}
	postOrderTraversal(pCur->getLeft());
	postOrderTraversal(pCur->getRight());
	std::cout << pCur->getData();
}

void BST::postOrderDestroy(BSTNode* pCur)
{
	if (pCur == nullptr)
	{
		return;
	}
	postOrderTraversal(pCur->getLeft());
	postOrderTraversal(pCur->getRight());
	delete pCur;
}

std::ostream& operator<<(std::ostream& rhs, BST& lhs)
{
	lhs.postOrderTraversal(); // filler for now. Would have to make more generic so it can print to any std::ostream not just std::cout;
	return rhs;
}