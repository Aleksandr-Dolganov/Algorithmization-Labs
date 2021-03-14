#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

int main()
{
    int a,b;
    int A[N];
    srand(time(NULL));
    for(int i = 0; i < N; i++)
    {
        A[i]=rand()%100;
        printf("%d ",A[i]);
    }
    printf("\n");
    for(int i = 1; i < N; i++)
    {
        a=A[i];
        b=i-1;
        while(b >= 0 && A[b] > a)
        {
            A[b+1]=A[b];
            b-=1;
        }
        A[b+1]=a;
    }
    for(int i = 0; i < N; i++)
    {
        printf("%d ",A[i]);
    }
}