#include "BST.hpp"

int main(void)
{
	BST B1;

	B1.insertNode("M");
	B1.insertNode("B");
	B1.insertNode("A");
	B1.insertNode("X");
	B1.insertNode("F");
	B1.insertNode("G");
	B1.insertNode("P");
	B1.insertNode("I");

	B1.inOrderTraversal();
	std::cout << std::endl;
	B1.preOrderTraversal();
	std::cout << std::endl;
	B1.postOrderTraversal();
	B1.destroyTree();
	return 0;
}