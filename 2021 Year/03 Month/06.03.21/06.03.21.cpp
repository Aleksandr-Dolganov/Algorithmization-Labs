#include <iostream>
#include <Windows.h>
//Стек на структуре (с меню).
using namespace std;

typedef struct list {
	float data;
	list* next;
}; list;

typedef struct stack {
	list* top;
} stack;

stack* stackCreate();
void makeNull(stack* S);
bool isEmpty(stack*);
float top(stack* S);
float pop(stack* S);
void push(float a, stack* S);
void menu(stack*);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	stack* S = nullptr;
	menu(S);
	return 0;
}

stack* stackCreate()
{
	stack* S;
	S = new stack;
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

float top(stack* S)
{
	if (S->top) {
		return (S->top->data);
	}
	else {
		return 0;
	}
}

float pop(stack* S)
{
	float a;
	list* p;
	p = S->top;
	a = p->data;
	S->top = p->next;
	free(p);
	return a;
}

void push(float a, stack* S)
{
	list* p;
	p = new list;
	p->data = a;
	p->next = S->top;
	S->top = p;
}

void menu(stack* S) {
	int Ex = 0;
	while (Ex != 404) {
		system("cls");
		cout << "1. Создать стек.\n2. Выполнить команду top.\n3. Выполнить команду pop.\n"
			<< "4. Выполнить команду push.\n5. Выход\n";
		int c;
		float x;
		cin >> c;
		system("cls");
		switch (c) {
		case 1: S = stackCreate(); break;
		case 2: if (!isEmpty(S)) { cout << top(S) << "\n"; system("PAUSE"); }
			  else { cout << "Ошибка стек пуст.\n"; system("PAUSE"); }; break;
		case 3: if (!isEmpty(S)) { cout << pop(S) << "\n"; system("PAUSE"); }
			  else { cout << "Ошибка стек пуст.\n"; system("PAUSE"); }; break;
		case 4: cout << "Введите число: "; cin >> x; push(x, S); break;
		case 5: Ex = 404; break;
		}
	}
}