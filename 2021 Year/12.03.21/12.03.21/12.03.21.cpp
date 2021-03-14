#include <iostream>
#include <windows.h>
#include <string>
//Стек на структуре. Перевод в обратную польскую запись.
using namespace std;

typedef struct list {
	char data;
	list* next;
}; list;

typedef struct stack {
	list* top;
} stack;

stack* stackCreate();
void makeNull(stack* S);
bool isEmpty(stack*);
char top(stack* S);
char pop(stack* S);
void push(char a, stack* S);
int priority(char a);
string polish(string);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string in, out;
	cout << "Введите выражение:\n";
	cin >> in;
	cout << polish(in);
	return 0;
}

stack* stackCreate()
{
	stack* S = new stack;
	S->top = nullptr;
	return S;
}

void makeNull(stack* S)
{
	list* p;
	while (S->top)
	{
		p = S->top;
		S->top = p->next;
		free(p);
	}
}

bool isEmpty(stack* S) {
	return (S == nullptr or S->top == nullptr);
}

char top(stack* S)
{
	if (S->top) {
		return (S->top->data);
	}
	else {
		return 0;
	}
}

char pop(stack* S)
{
	char a;
	list* p;
	p = S->top;
	a = p->data;
	S->top = p->next;
	free(p);
	return a;
}

void push(char a, stack* S)
{
	list* p;
	p = new list;
	p->data = a;
	p->next = S->top;
	S->top = p;
}

int priority(char a) {
	switch (a)
	{
	case '(':return 1; break;
	case ')':return 2; break;
	case '=':return 3; break;
	case '+':
	case '-':return 4; break;
	case '*':
	case '/':return 5; break;
	default:
		break;
	}
}

string polish(string in) {
	stack* S = stackCreate();
	string out = "";
	char x;
	int size = in.length(), j = 0;
	for (int i = 0; i < size; i++) {
		x = in[i];
		if (x >= '0' and x <= '9') {
			out.push_back(x);
			j++;
		}
		else {
			if (x == '(') {
				push(x, S);
			}
			else {
				if (x == ')') {
					while (top(S) != '(') {
						out.push_back(pop(S));
						j++;
					}
					pop(S);
				}
				else {
					while (!isEmpty(S) and priority(top(S)) >= priority(x)) {
						out.push_back(pop(S));
						j++;
					}
					push(x, S);
				}
			}
		}
	}
	while (!isEmpty(S)) {
		out.push_back(pop(S));
		j++;
	}
	out[j] = '\0';
	return out;
}