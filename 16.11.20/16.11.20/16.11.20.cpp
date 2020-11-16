#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int menu_exit;

/*Написать программу с  выбором из меню
1) сортировка выбором
2) сортировка пузырьком
3) быстрая сортировка
4) выход из программы
Задачи 1, 2 и 3 должны быть функциями*/

void show(int* a, int size);
int Menu(int* A, int size);
void selection_sort(int* a,int size);
void bubble_sort(int* a, int size);
void quick_sort(int* a, int left, int right);

int main()
{
	setlocale(LC_ALL, "");
	srand((unsigned)time(NULL));
	int size;
	printf("Введите размер массива: ");
	scanf_s("%d", &size);
	int* A = NULL;
	A = (int*)malloc(size * sizeof(int));
	for(int i = 0; i < size; i++)
	{
		A[i] = rand() % 51;
	}
	show(A,size);
	do
	{
		Menu(A, size);
	} while(menu_exit!=4);
	return 0;
}

int Menu(int* A, int size)
{
	int menu;
	printf("\n1) сортировка выбором\n2) сортировка пузырьком\n3) быстрая сортировка\n4) выход из программы\n");
	scanf_s("%d", &menu);
	switch(menu)
	{
		case 1: selection_sort(A, size); show(A, size); break;
		case 2: bubble_sort(A, size); show(A, size); break;
		case 3: quick_sort(A, 0, size - 1); show(A, size); break;
		case 4: menu_exit=4; break;
	}
	return 0;
}

void show(int* a, int size)
{
	printf("\n");
	for(int i = 0; i < size; i++)
	{
		printf("%d \t", a[i]);
	}
	printf("\n");
}

void selection_sort(int* a, int size)
{
	for(int i = 0; i < size; i++)
	{
		int minPos = i;
		for(int j = i + 1; j < size; j++)
			if(a[minPos] > a[j])
				minPos = j;
		int tmp = a[minPos];
		a[minPos] = a[i];
		a[i] = tmp;
	}
}

void bubble_sort(int* a,int size)
{
	for(int q = 0; q < size - 1; q++)
	{
		for(int w = 0; w < size - q - 1; w++)
		{
			if(a[w] > a[w + 1])
			{
				a[w] = a[w] + a[w + 1];
				a[w + 1] = a[w] - a[w + 1];
				a[w] = a[w] - a[w + 1];
			}
		}
	}
}

void quick_sort(int* a, int left, int right)
{
	int i = left, j = right, x = a[(left + right) / 2],tmp;
	do
	{
		while(a[i] < x)
		{
			i++;
		}
		while(a[j] > x)
		{
			j--;
		}
		if(i <= j)
		{
			if(a[i] > a[j])
			{
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
			i++;
			j--;
		}
	} while(i <= j);
	if(i < right)
	{
		quick_sort(a, i, right);
	}
	if(left < j)
	{
		quick_sort(a, left, j);
	}
}