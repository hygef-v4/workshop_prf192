/*When user chooses 1: User will enter values of date, month, year then the
program will announce whether this date is valid or not.
- -When user chooses 2: User will enter two characters, then the program will print
out ASCII codes of characters between them using descending order.*/
#include <stdio.h>
#include <stdbool.h>
#include <math.h>  

bool valid_date(int d, int m, int y);
void ascii(char c1, char c2);
int main(void)
{
    int n;
    int choice;

    do
    {
        printf("1- Check valid date\n");
        printf("2- Print Ascii table \n");
        printf("3- Quit\n");
        printf("Select an operation: ");
        scanf("%d", &choice);  

        switch (choice)
        {
        case 2:
            char c1,c2;
            ascii(c1, c2);
            printf("\n");
            break;

        case 1:
            int day, month, year;
            // input
            printf("Enter day/month/year: \n");
            scanf("%d/%d/%d", &day, &month, &year);

            // check 
            if (valid_date(day, month, year))
            {
                printf("Valid date\n");
            }
            else
            {
                printf("Invalid date\n");
            }

            
            break;
        }
    } while (choice > 0 && choice < 3);

    return 0;
}

    
bool valid_date(int d, int m, int y)
{
    int max_day = 31;
    // check case ko hop le
    if (d < 1 || m < 1 || m > 12)
    {
        return false;
    }
    // cap nhat cho cac thang co 30 ngay
    if (m==4 || m==6 || m==9 || m==11) 
    {
        max_day = 30;
    }
    // check nam nhuan
    else if (m == 2)
    {
        if (y%400 == 0 || (y%4 == 0 && y % 100 != 0))
        {
            max_day = 29;
        }
        else 
        {
            max_day = 28;
        }
    }
    // check 
    if (d > max_day)
    {
        return false;
    }
    return true;
}
void ascii(char c1, char c2)
{
    int d;
    printf("Enter character 1: ");
    scanf(" %c",&c1);
    
    printf("Enter character 2: ");
    scanf(" %c",&c2);
    
    printf("\nChar   Dec   Oct    Hex\n");
    
    for (char c = c2; c >= c1; c--)    // print character in descending order 
    {
        printf("%2c   %5d  %4o  %4X\n", c, c, c, c);
    }
}