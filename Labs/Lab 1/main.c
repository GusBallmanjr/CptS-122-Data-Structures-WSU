/*
	Programmer: Gus Ballman
	Class: Cpts 122, Fall 2025; Lab Section 01
	Programming assignment: Lab 1
	Date: August 16th, 2025
	Description:

*/

#include "Lab1.h"

int main(void)
{
	// Task 1:
	fputs("Hello World! I am in CptS 122!\n", stdout);

	// Task 2:
	char source[10] = "World", destination[20] = "Hello", name[4] = "Gus", output[20] = "";

	my_strcat(destination, source);
	fputs(destination, stdout);

	reverse(name);
	
	fputs(name, stdout);
	

	return 0;
}