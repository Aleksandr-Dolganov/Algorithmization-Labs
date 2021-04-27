#include "Stack.h"
#include <windows.h>
#include <string>
//Стек - класс с методами. Перевод в обратную польскую запись.
using namespace std;

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
	Stack S;
	S.stackCreate();
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
				S.push(x);
			}
			else {
				if (x == ')') {
					while (S.sTop() != '(') {
						out.push_back(S.pop());
						j++;
					}
					S.pop();
				}
				else {
					while (!S.isEmpty() and priority(S.sTop()) >= priority(x)) {
						out.push_back(S.pop());
						j++;
					}
					S.push(x);
				}
			}
		}
	}
	while (!S.isEmpty()) {
		out.push_back(S.pop());
		j++;
	}
	out[j] = '\0';
	return out;
}