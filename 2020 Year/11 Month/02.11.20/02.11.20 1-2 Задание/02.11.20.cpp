#include <stdio.h>
#define N 5

int main()
{
	int k;
	scanf_s("%d",&k);
	int A[N];
	for(int i = 0; i < N; i++)
	{
		scanf_s("%d", &A[i]);
	}
	for(int i = 0; i < k; i++)
	{
		int tmp = A[N - 1];
		for(int i = N - 1; i >= 1; i--)
		{
			A[i] = A[i - 1];
		}
		A[0] = tmp;
	}
	for(int i = 0; i < N; i++)
	{
		printf("%d ",A[i]);
	}
}