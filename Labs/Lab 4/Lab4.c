/*

*/

#include "Lab4.h"

stackNode* createNode(double newData)
{
	stackNode *pTop = malloc(sizeof(stackNode));
	if (pTop != NULL)
	{
		pTop->data = newData;
		pTop->pNext = NULL;
	}
	return pTop;
}

bool isEmpty(stackNode* pTop)
{
	bool success = false;
	if (pTop != NULL)
	{
		success = true;
	}
	return success;
}

bool push(stackNode** pTop, double newData)
{
	stackNode* pMem = createNode(newData);
	bool success = false;
	if (pMem != NULL)
	{
		pMem->data = newData;
		pMem->pNext = *pTop;
		*pTop = pMem;
		success = true;
	}
	return success;
}

void pop(stackNode** pTop)
{
	stackNode* pMem = *pTop;
	*pTop = pMem->pNext;
	free(pMem);
}

void peek(stackNode* pTop)
{
	fprintf(stdout, "%.2lf", pTop->data);
}

void printGame(stackNode* pTop1, stackNode* pTop2, stackNode* pTop3, int* postFrom, int* postTo)
{
	fprintf(stdout, "Post 1:\tPost 2:\tPost 3:\n");
	peek(pTop1);
	fprintf(stdout, "\t");
	peek(pTop2);
	fprintf(stdout, "\t");
	peek(pTop3);
	fprintf(stdout, "\n");

	fprintf(stdout, "What post would you like to grab from? ");
	scanf("%d", postFrom);
	fprintf(stdout, "Which post would you like to move that item to? ");
	scanf("%d", postTo);
	system("cls");
}

void movePost(int postFrom, int postTo, stackNode **pTop1, stackNode** pTop2, stackNode** pTop3)
{
	bool success = false;

	if (postFrom == 1 && postTo == 2 && *pTop1 != NULL && ((*pTop1)->data < (*pTop2)->data || (*pTop2)->data == 0))
	{
		success = push(pTop2, (*pTop1)->data);
		if (success == true)
		{
			bool status = isEmpty(*pTop1);
			if (status == true)
			{
				pop(pTop1);
			}
			//printGame(*pTop1, *pTop2, *pTop3, &postFrom, &postTo);
		}
	}
	else if (postFrom == 1 && postTo == 3 && *pTop1 != NULL && ((*pTop1)->data < (*pTop3)->data || (*pTop3)->data == 0))
	{
		success = push(pTop3, (*pTop1)->data);
		if (success == true)
		{
			bool status = isEmpty(*pTop1);
			if (status == true)
			{
				pop(pTop1);
			}
			//printGame(*pTop1, *pTop2, *pTop3, &postFrom, &postTo);
		}
	}
	else if (postFrom == 2 && postTo == 3 && *pTop2 != NULL && ((*pTop2)->data < (*pTop3)->data || (*pTop3)->data == 0))
	{
		success = push(pTop3, (*pTop2)->data);
		if (success == true)
		{
			bool status = isEmpty(*pTop2);
			if (status == true)
			{
				pop(pTop2);
			}
			//printGame(*pTop1, *pTop2, *pTop3, &postFrom, &postTo);
		}
	}
	else if (postFrom == 2 && postTo == 1 && *pTop2 != NULL && ((*pTop2)->data < (*pTop1)->data || (*pTop1)->data == 0))
	{
		success = push(pTop1, (*pTop2)->data);
		if (success == true)
		{
			bool status = isEmpty(*pTop2);
			if (status == true)
			{
				pop(pTop2);
			}
			//printGame(*pTop1, *pTop2, *pTop3, &postFrom, &postTo);
		}
	}
	else if (postFrom == 3 && postTo == 1 && *pTop3 != NULL && ((*pTop3)->data < (*pTop1)->data || (*pTop1)->data == 0))
	{
		success = push(pTop1, (*pTop3)->data);
		if (success == true)
		{
			bool status = isEmpty(*pTop3);
			if (status == true)
			{
				pop(pTop3);
			}
			//printGame(*pTop1, *pTop2, *pTop3, &postFrom, &postTo);
		}
	}
	else if (postFrom == 3 && postTo == 2 && *pTop3 != NULL && ((*pTop3)->data < (*pTop2)->data || (*pTop2)->data == 0))
	{
		success = push(pTop2, (*pTop3)->data);
		if (success == true)
		{
			bool status = isEmpty(*pTop3);
			if (status == true)
			{
				pop(pTop3);
			}
			//printGame(*pTop1, *pTop2, *pTop3, &postFrom, &postTo);
		}
	}
}