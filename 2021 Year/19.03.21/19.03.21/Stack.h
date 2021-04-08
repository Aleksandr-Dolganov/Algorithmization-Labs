#pragma once
#include <iostream>

typedef struct list {
	char data;
	list* next;
}; list;

typedef struct listInt {
	int data;
	listInt* next;
}; listInt;

class Stack
{
	list* top;
public:
	void stackCreate();
	bool isEmpty();
	char sTop();
	char pop();
	void push(char);
};

class StackInt
{
	listInt* top;
public:
	void stackCreate();
	bool isEmpty();
	int sTop();
	int pop();
	void push(int);
};