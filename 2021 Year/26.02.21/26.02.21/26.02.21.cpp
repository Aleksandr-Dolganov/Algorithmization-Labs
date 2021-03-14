#include <iostream>
#include <windows.h>
using namespace std;

struct list {
	int data;
	list* next;
}; list;

list* create_list(int num);
void read_list(list* head);
list* insert_to_list(int num, list* head);

int End = 0;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int num;
	string word;
	list* head = NULL;
	cout << "Введите первое число: ";
	cin >> num;
	head = create_list(num);
	while (End != 404) {
		cout << "\nВведите число: ";
		cin >> num;
		head = insert_to_list(num, head);
		cout << "Вывести список?\n";
		cin >> word;
		if (word == "y")
		{
			End = 404;
		}
	}
	read_list(head);
}

list* create_list(int num) {
	list* p = new list;
	p->data = num;
	p->next = NULL;
	return p;
}

void read_list(list* head) {
	list* p = head;
	while (p != NULL) {
		cout << p->data << "\t";
		p = p->next;
	}
}

list* insert_to_list(int num, list* head) {
	list* p = create_list(num);
	
	if (head->data > num) {
			p->next = head;
			head = p;
		}
	else {
		list* t = head;
		while (t->next != nullptr and t->next->data < num) {
			t = t->next;
		}
		p->next = t->next;
		t->next = p;
	}
	return head;
}