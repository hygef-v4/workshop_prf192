/*1- When the option 1 is selected, the program will accept a positive integral number,
called as n, then the first n Fibonacci numbers will be printed out
2- When the option 2 is selected, the program will accept a date then the program will
tell that whether this data is valid or not.
3- If the option 3 is selected, the program quits*/
#include <stdio.h>
#include <stdbool.h>
#include <math.h>  

void fibonacci(int n);
bool valid_date(int d, int m, int y);

int main(void)
{
    int n;
    int choice;

    do
    {
        printf("1- Print n Fibonacci\n");
        printf("2- Check valid date \n");
        printf("3- Quit\n");
        printf("Select an operation: ");
        scanf("%d", &choice);  

        switch (choice)
        {
        case 1:
            do
            {
                printf("Input n: ");
                scanf("%d", &n); 
            } while (n < 0);
            printf("First %d fibonacci: ", n);
            fibonacci(n);
            printf("\n");
            break;

        case 2:
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
void fibonacci(int n)
{
    int num_1 = 1;
    int num_2 = 1;
    int fib = 1;
    printf("%d, %d", num_1 , num_2);
    int i;
    for (i = 2; i < n; i++)  // loop to n - 1
    {
        fib = num_1 + num_2;
        num_1 = num_2;
        num_2 = fib;
        printf(", %d", fib);
    }
    
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

