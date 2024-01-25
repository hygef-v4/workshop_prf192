/* Write a C program that will carry out some times. In each time, a
nonnegative integer is accepted then print out the sum of its decimal
digits. The program will terminate when its value of accepted number
is negative.*/

#include <stdio.h>

int sum_digits(int n);
int main(void)
{
    int num;
    do
    {
        printf("Enter a positive number: \n");
        scanf("%d", &num);

        if (num >= 0)
        {
            int sum = sum_digits(num);
            printf("sum digit = %d\n", sum);
        }
    } while (num >= 0);
    
    return 0;
}
int sum_digits(int n)
{   
    int sum = 0;
    do
    {
        int remainder = n % 10;   // find leftmost digit
        n /= 10;                   // remaining digits
        sum += remainder;           // sum the digit
    } while (n > 0);        // n = 0 when no any digit left
    
    return sum;
}



