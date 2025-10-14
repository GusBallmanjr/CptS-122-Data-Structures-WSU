/*
	Programmer: Gus Ballman
	Class: Cpts 122, Fall 2025; Lab Section 01
	Programming assignment: Lab 1
	Date: August 16th, 2025
	Description:

*/

#ifndef LAB_H
#define LAB_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studentRecord
{
	char name[75];
	int ID;
	double GPA;
} StudentRecord;

void my_strcat(char* destination, const char* source);
char* reverse_string(char* p1, char* p2);
void reverse(char* string);
int fileLineparser(FILE* inputFileStream, struct* StudentRecord[]);


#endif