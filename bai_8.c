/*Making a real number from its integral part and its fraction (its
fraction must be positive).*/
#include <stdio.h>

double real_num(int x, int y);


int main(void)
{
    int ipart;
    int fraction;
    
    printf("Enter integral part: \n");
    scanf("%d", &ipart);
    do
    {
        printf("Enter fraction: \n");
        scanf("%d", &fraction);
    } while (fraction < 0);
    
    double result = real_num(ipart, fraction);
    printf("Real number: %lf", result);
    
    return 0;
}

double real_num(int x, int y)
{
    double fraction = y;
    double ipart = x;
    
    while (fraction >= 1)  
    { 
        fraction /= 10;    // 25 --> 2.5 --> 0.25
    }
    if (ipart < 0)         // negative integral part
    {
        return ipart - fraction;
    }

    return ipart + fraction;   // positive
}