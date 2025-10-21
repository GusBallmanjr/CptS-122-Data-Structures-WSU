#include "TestQueue.hpp"

Test::Test()
{
	pQueue = nullptr;
}

Queue* Test::getpQueue() const
{
	return pQueue;
}

void Test::setpQueue(Queue* const newpQueue)
{
	pQueue = newpQueue;
}

void Test::testEnqueueEmpty()
{
	Queue q1;
	Data d1;
	d1.setCustomer(1);
	d1.setService(5);
	d1.setTotal(20);
	d1.setGrocery(5);

	bool success = false;
	success = q1.enqueue(d1);
	std::cout << "enqueue: " << success << std::endl;
	std::cout << "enqueue->data: " << q1.getTailPtr()->getPData()->getData() << std::endl;
	std::cout << "HeadPtr: " << q1.getHeadPtr() << std::endl;
	std::cout << "TailPtr: " << q1.getTailPtr() << std::endl;
}

void Test::testEnqueue()
{
	Queue q1;
	Data d1, d2;
	d1.setCustomer(1);
	d1.setService(5);
	d1.setTotal(20);
	d1.setGrocery(5);
	d2.setCustomer(3);
	d2.setService(4);
	d2.setGrocery(4);
	d2.setTotal(400);

	bool success = false;
	success = q1.enqueue(d1);
	success = q1.enqueue(d2);

	std::cout << "enqueue: " << success << std::endl;
	std::cout << "enqueue->data: " << q1.getTailPtr()->getPData()->getData() << std::endl;
	std::cout << "HeadPtr: " << q1.getHeadPtr() << std::endl;
	std::cout << "TailPtr: " << q1.getTailPtr() << std::endl;
}

void Test::testDequeue1Node()
{
	Queue q3;
	Data d3;
	d3.setCustomer(-1);
	d3.setService(6);
	d3.setTotal(18);
	d3.setGrocery(6);
	
	q3.enqueue(d3);

	std::cout << "Before: HeadPtr: " << q3.getHeadPtr() << std::endl;
	std::cout << "Before: TailPtr: " << q3.getTailPtr() << std::endl;

	d3 = q3.dequeue();
	std::cout << "dequeue: " << d3 << std::endl;
	std::cout << "After: HeadPtr: " << q3.getHeadPtr() << std::endl;
	std::cout << "After: TailPtr: " << q3.getTailPtr() << std::endl;
}

void Test::testDequeue2Nodes()
{
	Queue q4;
	Data d4, d5;
	d4.setCustomer(-1);
	d4.setService(6);
	d4.setGrocery(6);
	d4.setTotal(18);
	d5.setCustomer(3);
	d5.setService(8);
	d5.setGrocery(8);
	d5.setTotal(19);

	q4.enqueue(d4);
	q4.enqueue(d5);

	std::cout << "Before: HeadPtr: " << q4.getHeadPtr() << std::endl;
	std::cout << "Before: TailPtr: " << q4.getTailPtr() << std::endl;

	d4 = q4.dequeue();
	std::cout << "dequeue: " << d4 << std::endl;
	std::cout << "After: HeadPtr: " << q4.getHeadPtr() << std::endl;
	std::cout << "After: TailPtr: " << q4.getTailPtr() << std::endl;
	d4 = q4.dequeue();
	std::cout << "dequeue: " << d4 << std::endl;
	std::cout << "After: HeadPtr: " << q4.getHeadPtr() << std::endl;
	std::cout << "After: TailPtr: " << q4.getTailPtr() << std::endl;
}

void Test::test24Hours()
{
	Queue ExpressLane, NormalLane;
	int arrivalExpress = 0, arrivalNormal = 0, numberExpress = 0, numberNormal = 0, currentNormal = 0, currentExpress = 0, timeStartExpress = 0, timeStartNormal = 0;
	Data normal, express;
	for (int time = 0; time < 1440; ++time) // 1440 minutes in a day
	{
		arrivalExpress = (rand() % 5) + 1;
		if (time % arrivalExpress == 0)
		{
			timeStartExpress = time;
			numberExpress++;
			express.setCustomer(numberExpress);
			express.setService((rand() % 5) + 1);
			express.setGrocery(express.getService());
			express.setTotal(-1);
			ExpressLane.enqueue(express);
		}

		if ((time % 10) == 0)
		{
			ExpressLane.printQueue(ExpressLane.getHeadPtr());
		}

		if (ExpressLane.getHeadPtr() != nullptr)
		{
			currentExpress = ExpressLane.getHeadPtr()->getPData()->getService();

			if (time == timeStartExpress + currentExpress)
			{
				ExpressLane.getHeadPtr()->getPData()->setTotal(time - timeStartExpress);
				express = ExpressLane.dequeue();
				std::cout << "Express lane: " << express << std::endl;
			}
		}
	}

	for (int time = 0; time < 1440; ++time)
	{
		arrivalNormal = (rand() % 6) + 3;
		if (time % arrivalNormal == 0)
		{
			timeStartNormal = time;
			numberNormal++;
			normal.setCustomer(numberNormal);
			normal.setService((rand() % 6) + 3);
			normal.setGrocery(normal.getService());
			normal.setTotal(-1);
			NormalLane.enqueue(normal);
		}

		if ((time % 10) == 0)
		{
			NormalLane.printQueue(NormalLane.getHeadPtr());
		}

		if (NormalLane.getHeadPtr() != nullptr)
		{
			currentNormal = NormalLane.getHeadPtr()->getPData()->getService();

			if (time == timeStartNormal + currentNormal)
			{
				NormalLane.getHeadPtr()->getPData()->setTotal(time - timeStartNormal);
				normal = NormalLane.dequeue();
				std::cout << "Normal lane: " << normal << std::endl;
			}
		}
	}
}