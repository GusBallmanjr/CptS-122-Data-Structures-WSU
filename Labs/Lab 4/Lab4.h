/*

*/

#ifndef LAB4_H
#define LAB4_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct stacknode
{
	double data;
	struct stacknode* pNext;
} stackNode;

typedef struct point
{
	int row, column;
} Point;

typedef struct mazenode
{
	Point coordinate;
	struct mazenode* pNext;
} mazeNode;

stackNode* createNode(double newData);
bool isEmpty(stackNode* pTop);
bool push(stackNode** pTop, double newData);
void pop(stackNode** pTop);
void peek(stackNode* pTop);
void printGame(stackNode* pTop1, stackNode* pTop2, stackNode* pTop3, int* postFrom, int* postTo);
void movePost(int postFrom, int postTo, stackNode** pTop1, stackNode** pTop2, stackNode** pTop3);

#endif