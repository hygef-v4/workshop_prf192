//Write a program that will accept a number (>=1 000 000 000)
//then show whether the number is an ISBN or not.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool checkISBN(int n);

int main(void)
{
    int n;
    printf("=============== ISBN Validator ==============\n");
    do
    {
        printf("ISBN (0 to quit): ");
        scanf("%d", &n);
        if (n == 0)         // if input = 0 --> terminate program
        {
            printf("Have a Nice Day!\n");
            break;
        }
            
        // 0003194876
        if(checkISBN(n))   
            printf("This is a valid ISBN.\n");
        else            
            printf("This is not a valid ISBN.\n");
    } while (true);
    
    return 0;
}

bool checkISBN(int n) 
{
	int N[10];                      // array contain digit n 

	int s = 0;                      // sum of value 
	int i, j;
    
    for (i = 9; i >= 0; i--) 
    {
        N[i] = n % 10;
        n /= 10;
    }

    // Calculate the sum 
    for (i = 0; i < 9; i++) 		//find digit
    {
        s += N[i] * (10 -i);
    }
    
    s += N[9];                      // + 10th element 
    // check last condition
    if ((s % 11) == 0)              
		return true;
	else
		return false;
}
