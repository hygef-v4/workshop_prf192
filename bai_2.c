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
    int total, x, y, count1, count2;
    do
    {
        printf("Enter your desired total sought: ");
        scanf("%d", &total);

    } while(total<2 || total > 20); 
    count1 = 1;  
    count2 = 2;

    do
    { 
        x= intRandom(1,10); //get random num for x and y 
        y= intRandom(1,10);
        printf("Result of pick %d and %d: %d + %d\n", count1, count2, x, y);
        count1 +=2;
        count2+=2;
    } while (x+y != total);
    printf("You got your total in %d throw", count2-2);
    return 0;
}