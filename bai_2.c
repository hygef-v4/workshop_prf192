// check valid date
#include <stdio.h>
#include <stdbool.h>

bool valid_date(int d, int m, int y);

int main(void)
{
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
