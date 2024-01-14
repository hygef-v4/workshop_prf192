#include <stdio.h>

int main()
{
    char c1, c2; 
    int d;
    printf("Enter character 1: ");
    scanf(" %c",&c1);
    
    printf("Enter character 2: ");
    scanf(" %c",&c2);
    
    if (c1 > c2)
    {
        int temp = c1;
        c1 = c2;
        c2 = temp;   // swap 
    }

    d = c2 - c1; 

    printf("\nDifference between c1 and c2 in ASCII: %d\n", d);
    printf("\nChar   Dec   Oct    Hex\n");
    
    for (char c = c1; c <= c2; c++)
    {
        printf("%c   %5d  %5o  %4X\n", c, c, c, c);
    }
    return 0;
}