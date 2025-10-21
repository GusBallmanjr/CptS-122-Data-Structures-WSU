#pragma once

#include "BSTNode.hpp"

class BST
{
public:
	BST();
	~BST();

	BSTNode* getRoot() const;
	void setRoot(BSTNode* const npRoot);

	void insertNode(std::string newData);
	
	void inOrderTraversal();
	void preOrderTraversal();
	void postOrderTraversal();
	bool isEmpty();
	void destroyTree();
private:
	BSTNode* pRoot;
	void insertNode(std::string newData, BSTNode* pCur);
	void inOrderTraversal(BSTNode* pCur);
	void preOrderTraversal(BSTNode* pCur);
	void postOrderTraversal(BSTNode* pCur);
	void postOrderDestroy(BSTNode* pCur);
};

std::ostream& operator<<(std::ostream& rhs, BST& lhs);