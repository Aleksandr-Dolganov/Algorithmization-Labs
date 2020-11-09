#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void show(int ** a, int size);

int main()
{
	setlocale(LC_ALL, "");
	srand((unsigned) time(NULL));
	int size;
	printf("Введите размер массива: ");
	scanf_s("%d", &size);
	int **A = NULL;
	A = (int **) malloc(size * sizeof(int *));
	for(int i = 0; i < size; i++)
	{
		A[i]=(int *) malloc(size * sizeof(int));
		for(int j = 0; j < size; j++)
		{
			A[i][j]=rand()%51;
		}
	}
	show(A,size);
}

void show(int ** a, int size)
{
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			printf("%d \t", a[i][j]);
		}
		printf("\n");
	}
}