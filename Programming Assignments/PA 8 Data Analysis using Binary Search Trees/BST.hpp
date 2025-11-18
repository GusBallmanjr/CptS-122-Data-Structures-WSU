#pragma once
#include "Node.hpp"
#include "TransactionNode.hpp"

class BST
{
public:
	BST();
	~BST();

	Node* getRoot() const { return pRoot; }
	void setRoot(Node* const newRoot) { pRoot = newRoot; }

	void insert(std::string const newData, int const newUnits);
	void inOrderTraversal();
	int findSmallest();
	int findLargest();
	std::string findData(int const findUnits);
private:
	Node* pRoot;
	void destroyTree(Node* pCur);
	void insert(std::string const newData, int const newUnits, Node* pCur);
	void inOrderTraversal(Node* pCur);
	int findLargest(Node* pCur, int max);
	int findSmallest(Node* pCur, int min);
	std::string findData(int const findUnits, Node* pCur, std::string type);
};