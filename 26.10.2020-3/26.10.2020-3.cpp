#include <stdio.h>

int matching(int, int);

int main()
{
	int N, a, b, c, d;
	scanf_s("%d", &N);
	a = N % 10;
	b = N / 10 % 10;
	c = N / 100 % 10;
	d = N / 1000;
	N=matching(a,b);
	N=matching(b,c);
	N=matching(c,d);
	printf("%d",N);
}

int matching(int a, int b)
{
	return (a > b) ? a : b;
}