/*


*/

#ifndef LAB3_H
#define LAB3_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum bool
{
	FALSE, TRUE
} Bool;

typedef struct contact
{
	char name[50], phone[12], email[50], title[20];
} Contact;

typedef struct node
{
	Contact data;
	struct node* pLink, * pPrev;
} Node;

Node* makeNode(Contact newData);
Bool insertContactAtFront(Node** pList, Contact newData);
Bool insertContactInOrder(Node** pList, Contact newData);
Bool deleteContact(Node** pList, Contact searchContact);
Bool editContact(Node* pList, Contact searchContact);
Bool loadContacts(FILE* infile, Node** pList);
Bool storeContacts(FILE* infile, Node* pList);
void printList(Node* pList);

#endif