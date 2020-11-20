#include "dynamic_array.h"

void array_show(int* A, int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%d\t", A[i]);
	}
	printf("\n");
}

int* array_enter(int size)
{
	int* A = NULL;
	A = (int*)malloc(size * sizeof(int));
	printf("\n");
	for(int i = 0; i < size; i++)
	{
		scanf_s("%d", &A[i]);
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