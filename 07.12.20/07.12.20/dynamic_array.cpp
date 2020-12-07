#include "dynamic_array.h"

using namespace std;

void array_show(int* a, int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << a[i] << "\t";
	}
	cout << "\n";
}

int* array_enter(int size)
{
	int* A = NULL;
	A = (int*)malloc(size * sizeof(int));
	cout << "\n";
	for(int i = 0; i < size; i++)
	{
		cin >> A[i];
	}
	return A;
}

int* array_rand(int size, int random)
{
	int* A = NULL;
	A = (int*)malloc(size * sizeof(int));
	for(int i = 0; i < size; i++)
	{
		A[i] = rand() % (random + 1);
	}
	return A;
}

int array_search(int* a, int size, int x)
{
	int i = 0;
	while(i < size && a[i] != x)
	{
		i++;
	}
	if(i < size)
	{
		return i;
	}
	else
	{
		return -1;
	}
}

int** matr_rand(int x, int y, int random)
{
	int** A = NULL;
	A = (int**)malloc(x * sizeof(int*));
	for(int i = 0; i < x; i++)
	{
		A[i] = (int*)malloc(y * sizeof(int));
		for(int j = 0; j < y; j++)
		{
			A[i][j] = rand() % (random + 1);
		}
	}
	return A;
}

void matr_show(int** a, int x, int y)
{
	cout << "\n";
	for(int i = 0; i < x; i++)
	{
		for(int j = 0; j < y; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << "\n\n";
	}
}