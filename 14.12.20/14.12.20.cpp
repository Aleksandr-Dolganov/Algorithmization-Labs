#include <iostream>
#include <windows.h>

int check(char* a, int s);
void swap(char* a, char* b);

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char* a;
	int size;
	std::cin >> size;
	a = (char*)malloc(size * sizeof(char));
	std::cin >> a;
	int i, j;
	do
	{
		i = size - 2;
		while(a[i] > a[i + 1])
		{
			i--;
		}
		j = i + 1;
		while(j < size and a[j] > a[i])
		{
			j++;
		}
		j--;
		swap(&a[i], &a[j]);
		for(int k = i + 1, j = size - 1; k < j; k++, j--)
		{
			swap(&a[k], &a[j]);
		}
		std::cout << "\nСледующая перестановка: " << a;
	}
	while(!check(a, size));
	return 0;
}

void swap(char* a, char* b)
{
	char tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int check(char* a, int s)
{
	for(int i = 0; i <= s - 2; i++)
	{
		if(a[i] < a[i + 1])
		{
			return 0;
		}
	}
	return 1;
}