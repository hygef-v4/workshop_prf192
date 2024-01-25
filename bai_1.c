// prime number to n
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_prime(int n);

int main(void)
{
    int n;
    do 
    {
        printf("Enter a number n: \n");
        scanf("%d", &n);
    } while (n < 2);

    for (int i = 2; i <= n; i++)
    {
        if(is_prime(i))
        {
            printf("%d is a prime number\n", i);
        }
    }

    return 0;
}
bool is_prime(int n)
{
    
    if (n < 2)  
    {
        return false;
    }
    
    for (int i = 2; i <= sqrt(n); i ++)    
    {
        if (n % i ==0)     
        {
            return false;
        }
    }

    return true;
}