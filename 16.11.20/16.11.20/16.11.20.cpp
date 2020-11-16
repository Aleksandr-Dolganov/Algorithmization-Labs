#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

/*Написать программу с  выбором из меню
1) сортировка выбором
2) сортировка пузырьком
3) быстрая сортировка
4) выход из программы
Задачи 1, 2 и 3 должны быть функциями*/

void show(int* a, int size);
void Menu(int* A, int size);
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
	Menu(A,size);
	return 0;
}

void Menu(int* A, int size)
{
	while(1)
	{
		int menu;
		printf("\n1) сортировка выбором\n2) сортировка пузырьком\n3) быстрая сортировка\n4) выход из программы\n");
		scanf_s("%d", &menu);
		if(menu == 4) break;

		switch(menu)
		{
			case 1: selection_sort(A, size); show(A, size); break;
			case 2: bubble_sort(A, size); show(A, size); break;
			case 3: quick_sort(A, 0, size - 1); show(A, size); break;
		}
	}
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
	int tmp;
	int old_l = left;
	int old_r = right;
	tmp = a[left];
	while(left < right)
	{
		while((a[right] >= tmp) && (left < right))
			right--;
		if(left != right)
		{
			a[left] = a[right];
			left++;
		}
		while((a[left] <= tmp) && (left < right))
			left++;
		if(left != right)
		{
			a[right] = a[left];
			right--;
		}
	}
	a[left] = tmp;
	tmp = left;
	left = old_l;
	right = old_r;
	if(left < tmp)
		quick_sort(a, left, tmp - 1);
	if(right > tmp)
		quick_sort(a, tmp + 1, right);
}