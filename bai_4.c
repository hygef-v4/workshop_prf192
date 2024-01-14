#include<stdio.h>

int main(){
    int x, y;
    int temp;
    do 
    {
        printf("Enter x: ");
        scanf("%d", &x);
        
        printf("Enter y: ");
        scanf("%d", &y);
        
        temp = x;
        x = y;
        y = temp;

        printf ("x = %d\n", x);
        printf ("y = %d\n", y);
       
    } while(x!=0 && y!=0);
    
    
    return 0;
}