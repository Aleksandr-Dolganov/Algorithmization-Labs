#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print(int * a, int size);

/* 1. С клавиатуры задается размер массива.
Объявляем указатель на массив и выделяем память под массив заданной длины.
Задать элементы массива rand() из интервала [-30, 80] и вывести на экран */

int main()
{
	srand(time(NULL));
	int size;
	printf("Enter array size: ");
	scanf_s("%d", &size);
	int * A;
	A = (int *) malloc(size * sizeof(int));
	for(int i = 0; i < size; i++)
	{
		A[i] = rand() % 111 - 30;
	}
	print(A, size);
}

void print(int * a, int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
}