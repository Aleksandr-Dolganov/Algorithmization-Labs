#include <iostream>
#include <windows.h>

int BM_substring_search(unsigned char s[], unsigned char q[]);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	unsigned char str1[99] = "привет друг мой, hello my friend";
	unsigned char word[20] = "мой, hello";
	int a = BM_substring_search(str1, word);
	int b = strlen((const char*)word);
	int c = strlen((const char*)str1);
	if(a > 0)
	{
		std::cout << a << "\n";
		for(int i = a, j = 0; j < b; i++, j++)
		{
			std::cout << str1[i];
		}
	}
	else
	{
		std::cout << "Такого слова не найдено.";
	}
}

int BM_substring_search(unsigned char s[], unsigned char q[])
{
	int d[256];
	int i, j, k, N, M;
	N = strlen((const char*)s);
	M = strlen((const char*)q);
	for(i = 0; i < 256; i++)
	{
		d[i] = M;
	}
	for(i = 0; i < M - 1; i++)
	{
		d[(unsigned char)q[i]] = M - i - 1;
	}
	i = M - 1;
	do
	{
		j = M - 1;
		k = i;
		while((j >= 0) && (q[j] == s[k]))
		{
			k--; j--;
		}
		if(j < 0) return k + 1;
		i += d[(unsigned)s[i]];
	}
	while(i < N);
	return -1;
}