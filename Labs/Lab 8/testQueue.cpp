#include "testQueue.hpp"


void testEnqueue()
{
	Queue q1;
	bool success = false;
	success = q1.enqueue("Hello");
	std::cout << "enqueue: " << success << std::endl;
	std::cout << "enqueue->data: " << q1.getTailPtr()->getData() << std::endl;
	std::cout << "HeadPtr: " << q1.getHeadPtr() << std::endl;
	std::cout << "TailPtr: " << q1.getTailPtr() << std::endl;
}

void testIsEmpty()
{
	Queue q2;
	bool success = false;
	q2.enqueue("Hi");
	success = q2.isEmpty();
	std::cout << "isEmpty(q2): " << success << std::endl;

	Queue q3;

	success = q3.isEmpty();
	std::cout << "isEmpty(q3): " << success << std::endl;
}

void testDequeue()
{
	Queue q4;
	std::string data;
	q4.enqueue("YOOOOOOOOOO");

	std::cout << "Before: HeadPtr: " << q4.getHeadPtr() << std::endl;
	std::cout << "Before: TailPtr: " << q4.getTailPtr() << std::endl;

	data = q4.dequeue();
	std::cout << "dequeue: " << data << std::endl;
	std::cout << "After: HeadPtr: " << q4.getHeadPtr() << std::endl;
	std::cout << "After: TailPtr: " << q4.getTailPtr() << std::endl;

	q4.enqueue("Hi");
	q4.enqueue("Yoo");
	std::cout << "Before: HeadPtr: " << q4.getHeadPtr() << std::endl;
	std::cout << "Before: TailPtr: " << q4.getTailPtr() << std::endl;
	data = q4.dequeue();
	std::cout << "dequeue: " << data << std::endl;
	std::cout << "After: HeadPtr: " << q4.getHeadPtr() << std::endl;
	std::cout << "After: TailPtr: " << q4.getTailPtr() << std::endl;
}

void testPrint()
{
	Queue q5;
	q5.enqueue("Hi,");
	q5.enqueue("my");
	q5.enqueue("name");
	q5.enqueue("is");
	q5.enqueue("Gus.");

	q5.printQueue(q5.getHeadPtr());
}