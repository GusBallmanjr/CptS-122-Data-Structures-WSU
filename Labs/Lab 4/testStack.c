/*

*/

#include "Lab4.h"
#include "testStack.h"

bool testPush(stackNode** pTop, double newData)
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

void testPeek(stackNode* pTop)
{
	fprintf(stdout, "Data at the top of the stack: %.2lf\n", pTop->data);
}