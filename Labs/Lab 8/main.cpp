#include "Node.hpp"
#include "Queue.hpp"
#include "testQueue.hpp"

int main(void)
{
	std::cout << std::endl << std::endl << "Enqueue: " << std::endl;
	testEnqueue();
	std::cout << std::endl << std::endl << "Is Empty: " << std::endl;
	testIsEmpty();
	std::cout << std::endl << std::endl << "Dequeue: " << std::endl;
	testDequeue();
	std::cout << std::endl << std::endl << "Print Queue: " << std::endl;
	testPrint();

	return 0;
}