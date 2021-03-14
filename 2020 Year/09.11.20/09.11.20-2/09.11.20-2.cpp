#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void print(int * a, int size);
int search(int * a, int x, int size);
int multiplication(int * A, int size, int y);

/* 2. С клавиатуры задается размер массива.
Объявляем указатель на массив и выделяем память под массив заданной длины.
Задать элементы массива rand() из интервала [20, 70] и число X.
Написать функцию поиска числа X  в массиве.
Фунция возращает порядковый номер или если нет число, то -1.
Если число Х есть, то  вычислить произведение элементов массива от Х до конца массива,
иначе выдать нет такого числа. */

int main()
{
	setlocale(LC_ALL, "");
	srand((unsigned) time(NULL));
	int size;
	printf("Введите размер массива: ");
	scanf_s("%d", &size);
	int * A = NULL;
	A = (int *) malloc(size * sizeof(int));
	for(int i = 0; i < size; i++)
	{
		A[i] = rand() % 50 + 20;
	}
	print(A, size);
	int x = 0, y;
	printf("\nВведите x: ");
	scanf_s("%d", &x);
	y = search(A, x, size);
	if(y == -1)
	{
		printf("x отсутствует в массиве.");
	}
	else
	{
		printf("Произведение чисел от заданного до конца: %d", multiplication(A, size, y));
	}
	free(A);
}

void print(int * a, int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
}

int search(int * a, int x, int size)
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

int multiplication(int * A, int size, int y)
{
	int res = 1;
	for(int i = y, j = size; i < j; i++)
	{

		res *= A[i];
	}
	return res;
}