#pragma once
#include "Queue.hpp"

class Test
{
public:
	Test();

	Queue* getpQueue() const;
	void setpQueue(Queue* const newpQueue);

	void testEnqueueEmpty();
	void testEnqueue();
	void testDequeue1Node();
	void testDequeue2Nodes();
	void test24Hours();
private:
	Queue* pQueue;
};