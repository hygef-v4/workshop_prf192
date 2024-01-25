// find the max min digit
#include <stdio.h>

void maxmin_digit(int n);

int main(void)
{
    int num;
    do
    {
        printf("Enter a positive number: \n");
        scanf("%d", &num); 

    } while (num < 0);
    maxmin_digit(num);
    return 0;
}

void maxmin_digit(int n)
{                  
    int digit; 
    int max, min;    
    digit = n % 10;     //find the left most digit
    n /= 10;               // remaining digits
    min = max = digit;  
 
    while(n > 0)  // n = 0 when no digit left
    {
        digit = n % 10;  // find the next digit  
        n /= 10;      
        
        //check max min
        if(digit < min)   
        { 
            min = digit; 
        }

        if(digit > max) 
        {
            max = digit;
        }
    }
    
    printf("Max digit: %d\n", max); 
    printf("Min digit: %d\n", min);  
}
