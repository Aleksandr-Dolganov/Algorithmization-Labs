#pragma once
#include <iostream>

typedef struct list {
	char data;
	list* next;
}; list;

class Stack
{
	list* top;
public:
	void stackCreate();
	bool isEmpty();
	char sTop();
	char pop();
	void push(char a);
};

