/* 1- When user selects the option 1, the program will accept a
positive integral number and print out a message about
whether the input number is a prime or not.
2- When user selects the option 2, the program will accept a
positive integral number and print out the minimum and
maximum digit in this number.
3- The program will terminate when user selects the option 3.*/
#include <stdio.h>
#include <stdbool.h>
#include <math.h>  

bool is_prime(int n);
void maxmin_digit(int n);

int main(void)
{
    int n;
    int choice;

    do
    {
        printf("1- Process primes\n");
        printf("2- Print min, max digit in an integer \n");
        printf("3- Quit\n");
        printf("Select an operation: ");
        scanf("%d", &choice);  

        switch (choice)
        {
        case 1:
            do
            {
                printf("Input n: ");
                scanf("%d", &n); 
            } while (n < 0);
            
            if (is_prime(n))
            {
                printf("%d is a prime number\n", n);
            }
            else
            {
                printf("%d is not a prime number\n", n);
            }
            break;

        case 2:
            do
            {
                printf("Input n: ");
                scanf("%d", &n);  
            } while (n < 0);
            maxmin_digit(n);
            break;
        }
    } while (choice > 0 && choice < 3);

    return 0;
}

bool is_prime(int n)
{
    if (n < 2)
    {
        return false;
    }
    int i;
    for (i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

void maxmin_digit(int n)
{
    int digit;
    int max, min;
    digit = n % 10;
    n /= 10;
    min = max = digit;

    while (n > 0)
    {
        digit = n % 10;
        n /= 10;

        if (digit < min)
        {
            min = digit;
        }

        if (digit > max)
        {
            max = digit;
        }
    }

    printf("Max digit: %d\n", max);
    printf("Min digit: %d\n", min);
}
