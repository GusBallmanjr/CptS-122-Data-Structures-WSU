/*

*/

#include "Lab4.h"
#include "testStack.h"

int main(void)
{
	stackNode* pTop1 = NULL, *pTop2 = NULL, *pTop3 = NULL;
	bool success = false, loop = false;
	int postFrom = 0, postTo = 0;

	/*success = testPush(&pTop, 100.02);
	if (success == true)
	{
		testPeek(pTop);
	}*/

	// Tower of Hanoi:
	success = push(&pTop1, 00);
	if (success == true)
	{
		success = push(&pTop1, 3);
		if (success == true)
		{
			success = push(&pTop1, 2);
			if (success = true)
			{
				success = push(&pTop1, 1);
				if (success = true)
				{
					goto label1;
				}
			}
		}
	}

label1:
	success = push(&pTop2, 000);
	if (success == true)
	{
		success = push(&pTop2, 000);
		if (success == true)
		{
			success = push(&pTop2, 000);
			if (success = true)
			{
				success = push(&pTop2, 000);
				if (success = true)
				{
					goto label2;
				}
			}
		}
	}

label2:
	success = push(&pTop3, 000);
	if (success == true)
	{
		success = push(&pTop3, 000);
		if (success == true)
		{
			success = push(&pTop3, 000);
			if (success = true)
			{
				success = push(&pTop3, 000);
				if (success = true)
				{
					goto label3;
				}
			}
		}
	}

label3:
	while(loop == false)
	{
		printGame(pTop1, pTop2, pTop3, &postFrom, &postTo);
		movePost(postFrom, postTo, &pTop1, &pTop2, &pTop3);
		if (pTop3->data == 1 && pTop3->pNext->data == 2 && pTop3->pNext->pNext->data == 3)
		{
			loop = true;
		}
	}
	fprintf(stdout, "You Won!!!\n");
	system("pause");
	system("cls");
	// Maze

	mazeNode* pTop = NULL;
	char maze[10][10] = { {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
						{ '1', ' ', ' ', ' ', ' ', '0', '0', ' ', ' ', '0'},
						{ '0', '0', '0', ' ', '0', '0', '0', ' ', '0', '0'},
						{ '0', ' ', ' ', ' ', ' ', '0', '0', ' ', '0', '0'},
						{ '0', ' ', '0', '0', '0', '0', '0', ' ', ' ', '0'},
						{ '0', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '0', '0'},
						{ '0', '0', '0', '0', '0', '0', ' ', '0', '0', '0'},
						{ '0', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '0', '0'},
						{ '0', ' ', ' ', '0', '0', '0', '0', ' ', '0', '0'},
						{ '0', '1', '0', '0', '0', '0', '0', '0', '0', '0'}};
	Point startPoint = { .row = 9, .column = 1 };
	//push(&pTop, startPoint);

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			fprintf(stdout, "%c", maze[i][j]);
		}
		fprintf(stdout, "\n");
	}
	return 0;
}