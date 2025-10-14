/*
	Programmer: Gus Ballman
	Class: Cpts 122, Fall 2025; Lab Section 01
	Programming assignment: Lab 1
	Date: August 16th, 2025
	Description:

*/

#include "Lab1.h"

void my_strcat(char* destination, const char* source)
{
	int length_destination = 0, length_source = 0;
	while (source[length_source] != '\0')
	{
		++length_source;
	}
	while (destination[length_destination] != '\0')
	{
		++length_destination;
	}
	for (int i = 0; i < length_source; i++)
	{
		destination[length_destination + i] = source[i];
	}
}

char* reverse_string(char* p1, char* p2)
{
	char temp;
	if (p2 >= p1)
	{
		return 'c';
	}
	else if (p2 != p1)
	{
		temp = *p1;
		*p1 = *p2;
		*p2 = temp;
		reverse_string(p1 + 1, p2 - 1);
	}
}

void reverse(char* string)
{
	char* beginning = string;
	char* end = string + strlen(string) - 1;
	reverse_string(beginning, end);
}

char* my_strtok(char* str, char* delim)
{
	static char* next_token;
	int i = 0;
	if (str != NULL)
	{
		next_token = str;
		while (str[i] != delim && str != '\0')
		{
			++i;
		}
		str[i] = '\0';
		next_token = str + i;
	}
	return next_token;
}