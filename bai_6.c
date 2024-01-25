/* Write a C program that will accept a positive integer then print out
whether it is an element of the Fibonacci sequence or not.*/
#include <stdio.h>
#include <stdbool.h>

bool is_fib(int n);
int main(void)
{
    int num;
    
    do
    {   
        printf("Enter a number: \n");
        scanf("%d", &num);
    } while (num < 1);
    
    if (is_fib(num))
    {
        printf("%d is a fibonacci element\n", num);
    }
    else 
    {
        printf("%d is not a fibonacci element\n", num);
    }
    
    return 0;
}
bool is_fib(int n)
{
    int t1 = 1;
    int t2 = 1;
    int fib = 1;
    
    if (n == 1)
    {
        return true;
    }
    while(fib < n)
    {
        fib = t1 + t2;
        t1 = t2;
        t2 = fib;
    }
    return n == fib; // true or false
}



