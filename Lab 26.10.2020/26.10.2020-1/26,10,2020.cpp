#include <stdio.h>

int lucky_ticket(int);

int main()
{
    int ticket_number,flag;
    for(int ticket_number = 100000; ticket_number <= 999999; ticket_number++)
    {
        flag = lucky_ticket(ticket_number);
        if(flag == 1)
        {
            printf("%d Lucky ticket\n", ticket_number);
        }
    }
}

int lucky_ticket(int ticket_number)
{
    int A[6];
    for(int i = 0; i < 6; i++)
    {
        A[i]=ticket_number % 10;
        ticket_number /= 10;
    }
    if((A[0] + A[1] + A[2]) == (A[3] + A[4] + A[5]))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}