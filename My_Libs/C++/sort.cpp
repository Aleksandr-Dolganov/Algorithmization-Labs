#include "sort.h"

using namespace std;

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

void siftDown(int* a, int root, int bottom)
{
	int maxChild;
	int done = 0;
	while((root * 2 <= bottom) && (!done))
	{
		if(root * 2 == bottom)
			maxChild = root * 2;
		else if(a[root * 2] > a[root * 2 + 1])
			maxChild = root * 2;
		else
			maxChild = root * 2 + 1;
		if(a[root] < a[maxChild])
		{
			int temp = a[root];
			a[root] = a[maxChild];
			a[maxChild] = temp;
			root = maxChild;
		}
		else
			done = 1;
	}
}

void heap_sort(int* a, int size)
{
	for(int i = (size / 2) - 1; i >= 0; i--)
		siftDown(a, i, size - 1);
	for(int i = size - 1; i >= 1; i--)
	{
		int temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		siftDown(a, 0, i - 1);
	}
}