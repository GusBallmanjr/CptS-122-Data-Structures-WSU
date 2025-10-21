
#include "Queue.hpp"
#include "TestQueue.hpp"

int main(void)
{
	srand(time(NULL));

	Queue ExpressLane, NormalLane;
	int arrivalExpress = 0, arrivalNormal = 0, numberExpress = 0, numberNormal = 0, currentNormal = 0, currentExpress = 0, timeStartExpress = 0, timeStartNormal = 0, simulation = 0;
	Data normal, express;
	/*Test t;
	t.testEnqueueEmpty();
	t.testEnqueue();
	t.testDequeue1Node();
	t.testDequeue2Nodes();
	t.test24Hours();*/

	main:
	std::cout << "How many minutes would you like to run the simulation for\? " << std::endl;
	std::cin >> simulation;

	if (simulation < 0)
	{
		std::cout << "Invalid Input, Try Again." << std::endl;
		goto main;
	}

	arrivalExpress = 1;

	for (int time = 0; time < simulation; ++time)
	{

		if (time == timeStartExpress + arrivalExpress)
		{
			arrivalExpress = (rand() % 5) + 1;
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

	arrivalNormal = 5;

	for (int time = 0; time < simulation; ++time)
	{

		if (time == timeStartNormal + arrivalNormal)
		{
			arrivalNormal = (rand() % 6) + 3;
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

	return 0;
}