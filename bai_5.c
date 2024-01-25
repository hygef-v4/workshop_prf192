// value of nth position in fibonacci 
#include <stdio.h>

int fib(int n);

int main(void)
{
    int length;
    
    do
    {   
        printf("Enter length (length >= 1) \n");
        scanf("%d", &length);
    } while (length < 1);
    
    printf("Fibonacci in position %d: %d\n", length, fib(length));
    return 0;
}

int fib(int n)
{
    int num_1 = 1;
    int num_2 = 1;
    int fib = 1;

    for (int i = 2; i < n; i++)  // loop to n - 1
    {
        fib = num_1 + num_2;
        num_1 = num_2;
        num_2 = fib;

    }
    return fib;
}


