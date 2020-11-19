#include "sort.h"

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