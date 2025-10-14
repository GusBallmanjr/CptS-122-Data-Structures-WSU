/*


*/

#include "Lab3.h"

int main(void)
{
	Contact contacts = { .name = "Gus", .phone = "5092901067", .email = "gus.ballman@wsu.edu", .title = "student" }, * headPtr = NULL, contact2 = { .name = "TOMMY", .phone = "5094951080", .email = "bill@wsu.edu", .title = "skool" }, searchContact = { .name = "Gus", .phone = "5094951080", .email = "bill@wsu.edu", .title = "skool" };


	headPtr = makeNode(contact2);
	//printList(headPtr);
	//insertContactAtFront(&headPtr, contact2);
	insertContactInOrder(&headPtr, contacts);
	//deleteContact(&headPtr, searchContact);
	printList(headPtr);


	return 0;
}