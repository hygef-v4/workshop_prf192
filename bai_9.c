/* Find out the greatest common divisor (gcd) and least common
multiple (lcm) of two positive integers:*/
#include <stdio.h>

int gcd(int a, int b);
int lcm(int a, int b);

int main(void)
{
    int num_1;
    int num_2;
    do
    {
        printf("enter num 1: \n");
        scanf("%d", &num_1);
        printf("enter num 2: \n");
        scanf("%d", &num_2);
    } while (num_1 <= 0 || num_2 <=0);
    
    int d = gcd(num_1, num_2);
    int m = lcm(num_1, num_2);

    printf("GCD of %d and %d is: %d\n", num_1, num_2, d);
    printf("LCM of %d and %d is: %d\n", num_1, num_2, m);
    
    return 0;
}
int gcd(int a, int b)
{
    while(a!=b)   //lấy số lớn trừ số bé cho tới khi 2 số bằng nhau thì là gcd
    {
        if (a>b)
        {
            a -=b;
        }
        else
        {
            b -=a;   
        }
    }
    return a;
}
int lcm(int a, int b)
{
    return a*b / gcd(a,b);   // gcd x lcm = a x b
}
