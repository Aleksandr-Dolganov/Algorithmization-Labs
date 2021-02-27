#include <iostream>

void strreverse(char[]);

/*4. Ввести символьную строку. Напишите функцию, которая перевернет эту строку.
	Например, если ввели строку «abcdef», то в результате в ней должны получить «fedcba».*/

int main()
{
	char a[40];
	gets_s(a);
	strreverse(a);
	puts(a);
}

void strreverse(char a[])
{
	int size = strlen(a);
	for(int i = 0; i < size / 2; i++)
	{
		char tmp = a[i];
		a[i] = a[size - i - 1];
		a[size - i - 1] = tmp;
	}
}