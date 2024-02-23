#include <stdio.h>
#include <stdlib.h>  // library for rand()
#include <time.h> 
int intRandom(int min, int max)
{
    int result;
    
    // random num from min to max
    return result = (rand() % (max - min + 1)) + min;  
                       
}               
int main(void)
{
    srand(time(NULL));  // ensure different results in the next run
    int total, x, y, count;
    do
    {
        printf("Enter your desired total sought: ");
        scanf("%d", &total);

    } while(total<2 || total > 12); // roll from 1 - 6
    count = 1;  // roll start with 1 

    do
    { 
        x= intRandom(1,6);
        y= intRandom(1,6);
        printf("Result of throw %d: %d + %d\n", count, x, y);
        count++;
    } while (x+y != total);
    printf("You got your total in %d throw", count-1);
    return 0;
}