// factorial of a number
#include <stdio.h>

int factorial(int n);

int main(void)
{
    int num;
    
    printf("Enter a number: \n");
    scanf("%d", &num);
    
    int result = factorial(num);
    printf("Factorial of %d is: %d\n", num, result);
    return 0;
}
int factorial(int n)  // dùng recursion
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n*factorial(n-1);
}

