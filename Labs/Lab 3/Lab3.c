/*


*/

#include "Lab3.h"

Node* makeNode(Contact newData)
{
	Node* pMem = malloc(sizeof(Node));
	if (pMem != NULL)
	{
		pMem->pLink = NULL;
		pMem->pPrev = NULL;
		strcpy(pMem->data.name, newData.name);
		strcpy(pMem->data.phone, newData.phone);
		strcpy(pMem->data.email, newData.email);
		strcpy(pMem->data.title, newData.title);
	}
	return pMem;
}

Bool insertContactAtFront(Node** pList, Contact newData)
{
	Node* pCur = makeNode(newData);
	if (*pList == NULL)
	{
		*pList = makeNode(newData);
		return TRUE;
	}
	if (pCur != NULL && *pList != NULL)
	{
		pCur->pLink = *pList;
		(*pList)->pPrev = pCur;
		pCur->pPrev = NULL;
		*pList = pCur;
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

Bool insertContactInOrder(Node** pList, Contact newData)
{
	Node* pCur = makeNode(newData), *pNext = *pList;
	Bool success = FALSE;
	while (success == FALSE)
	{
		if (pCur == NULL)
		{
			break;
		}
		if (pCur != NULL && pNext != NULL && strcmp(pCur->data.name, pNext->data.name) > 0)
		{
			if (pNext->pLink == NULL)
			{
				// Enters in alphabetically at the end
				pCur->pLink = pNext->pLink;
				pNext->pLink = pCur;
				pCur->pPrev = pNext;
				success = TRUE;
			}
			else if (strcmp(pCur->data.name, pNext->pLink->data.name) < 0)
			{
				// Enters in alphabetically
				pCur->pLink = pNext->pLink;
				pNext->pLink = pCur;
				pCur->pPrev = pNext;
				pCur->pLink->pPrev = pCur;
				success = TRUE;
			}
			else if ((strcmp(pCur->data.name, pNext->pLink->data.name) > 0))
			{
				// needs to move along linked list
				pNext = pNext->pLink;
			}

		}
		else // Comes before first node alphabetically
		{
			if (pCur != NULL)
			{
				pCur->pLink = *pList;
				(*pList)->pPrev = pCur;
				pCur->pPrev = NULL;
				*pList = pCur;
				success = TRUE;
			}
		}
	}
	return success;
}

Bool deleteContact(Node** pList, Contact searchContact)
{
	Node* pCur = *pList;
	Bool success = FALSE;

	while (success == FALSE)
	{
		if (strcmp(pCur->data.name, searchContact.name) == 0 && pCur == (*pList))
		{
			// Found Contact
			*pList = pCur->pLink;
			(*pList)->pPrev = pCur->pPrev;
			(*pList)->pPrev->pLink = (*pList); //
			free(pCur);
			success = TRUE;
		}
		else if (strcmp(pCur->data.name, searchContact.name) == 0 && pCur != (*pList))
		{
			pCur->pPrev->pLink = pCur->pLink;
			pCur->pLink->pPrev = pCur->pPrev;
			free(pCur);
		}
		else
		{
			// needs to move along linked list
			if (pCur->pLink == NULL && success == FALSE)
			{
				break; // Not Found before end of list
			}
			else
			{
				pCur = pCur->pLink;
			}
		}
	}
	return success;
}

Bool editContact(Node* pList, Contact searchContact)
{
	Node* pCur = pList;
	Bool success = FALSE;
	char change[50] = "";

	while (success == FALSE)
	{
		if (strcmp(pCur->data.name, searchContact.name) == 0)
		{
			// Found Contact
			strcpy(pCur->data.name, change);
			success == TRUE;
		}
		else
		{
			// needs to move along linked list
			if (pCur->pLink == NULL && success == FALSE)
			{
				break; // Not Found before end of list
			}
			else
			{
				pCur = pCur->pLink;
			}
		}
	}
	return success;
}

Bool loadContacts(FILE* infile, Node** pList)
{
	Node* pCur = *pList;
	Contact newdata = { .name = "", .phone = "", .email = "", .title = "" };
	char str[150] = "";
	if (pCur == NULL)
	{
		return FALSE;
	}
	while (!feof(infile))
	{
		fgets(str, 150, infile);
		strcpy(pCur->data.name, strtok(str, ","));
		strcpy(pCur->data.phone, strtok(NULL, ","));
		strcpy(pCur->data.email, strtok(NULL, ","));
		strcpy(pCur->data.title, strtok(NULL, ","));
		insertContactInOrder(pList, newdata);
		pCur = pCur->pLink;
	}
	return TRUE;
}

Bool storeContacts(FILE* infile, Node* pList)
{
	Node* pCur = pList;

	if (pCur == NULL)
	{
		return FALSE;
	}
	while (pCur != NULL)
	{
		fprintf(infile, pList->data.name);
		fprintf(infile, pList->data.phone);
		fprintf(infile, pList->data.email);
		fprintf(infile, pList->data.title);
		pCur = pCur->pLink;
	}
	return TRUE;
}

void printList(Node* pList)
{
	Node* pCur = pList;
	if (pList == NULL)
	{
		fprintf("List is Empty\n", stdout);
	}
	while (pCur != NULL)
	{
		fputs(pCur->data.name, stdout);
		fprintf(stdout, "\t");
		fputs(pCur->data.phone, stdout);
		fprintf(stdout, "\t");
		fputs(pCur->data.email, stdout);
		fprintf(stdout, "\t");
		fputs(pCur->data.title, stdout);
		fprintf(stdout, "\n");
		pCur = pCur->pLink;
	}
}