#include<stdio.h>

int main(){
    int sum = 0;
    int x;
    do 
    {
        printf("Enter number: ");
        scanf("%d", &x);
        if (x != 0)
        {
            sum += x; 
        }
    } while(x!=0);
    printf ("Sum = %d", sum);
    return 0;
}