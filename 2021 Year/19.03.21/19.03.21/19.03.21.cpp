#include "Stack.h"
#include <windows.h>
#include <string>
//Стек - класс с методами. Перевод в обратную польскую запись.
using namespace std;

int priority(char a);
string polish(string);
int calculatePolish(string);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string in, out;
	cout << "Введите выражение:\n";
	cin >> in;
	out = polish(in);
	cout << out;
	cout << "\nОтвет: " << calculatePolish(out);
	return 0;//20+15-5*(3-2+10/2)
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
		if (in[i] == '+' or in[i] == '-' or in[i] == '*' or in[i] == '/') {
			out.push_back('#');
			j++;
		}
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

int calculatePolish(string in) {
	StackInt S;
	int a, b, c, tmp = 0, tmp1;
	S.stackCreate();
	char x;
	int size = in.length();
	for (int i = 0; i < size; i++) {
		while (in[i] >= '0' and in[i] <= '9' and in[i] != '#') {
			tmp1 = (int)in[i] - '0';
			tmp = (tmp * 10) + tmp1;
			i++;
		}
		if (tmp != 0) { S.push(tmp); }
		tmp = 0;
		x = in[i];
		if (x == '+' or x == '-' or x == '*' or x == '/') {
			b = S.pop();
			a = S.pop();
			switch (x) {
			case '+': c = a + b; S.push(c); break;
			case '-': c = a - b; S.push(c); break;
			case '*': c = a * b; S.push(c); break;
			case '/': c = a / b; S.push(c); break;
			}
		}
	}

	return S.pop();
}