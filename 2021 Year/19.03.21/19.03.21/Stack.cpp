#include "Stack.h"
void Stack::stackCreate()
{
	top = nullptr;
}

bool Stack::isEmpty() {
	return (top == nullptr);
}

char Stack::sTop()
{
	if (top) {
		return (top->data);
	}
	else {
		return 0;
	}
}

char Stack::pop()
{
	char a;
	list* p;
	p = top;
	a = p->data;
	top = p->next;
	free(p);
	return a;
}

void Stack::push(char a)
{
	list* p;
	p = new list;
	p->data = a;
	p->next = top;
	top = p;
}

////////////////////////////////////////////////////////////////////////////////////
void StackInt::stackCreate()
{
	top = nullptr;
}

bool StackInt::isEmpty() {
	return (top == nullptr);
}

int StackInt::sTop()
{
	if (top) {
		return (top->data);
	}
	else {
		return 0;
	}
}

int StackInt::pop()
{
	int a;
	listInt* p;
	p = top;
	a = p->data;
	top = p->next;
	free(p);
	return a;
}

void StackInt::push(int a)
{
	listInt* p;
	p = new listInt;
	p->data = a;
	p->next = top;
	top = p;
}