#include <iostream>
#include <windows.h>
#include <string>
#include <stack>
//Стек - библиотека. Перевод в обратную польскую запись.
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
	stack <char> S;
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
					while (S.top() != '(') {
						out.push_back(S.top());
						S.pop();
						j++;
					}
					S.pop();
				}
				else {
					while (!S.empty() and priority(S.top()) >= priority(x)) {
						out.push_back(S.top());
						S.pop();
						j++;
					}
					S.push(x);
				}
			}
		}
	}
	while (!S.empty()) {
		out.push_back(S.top());
		S.pop();
		j++;
	}
	out[j] = '\0';
	return out;
}