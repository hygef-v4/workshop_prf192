/*Write a C program that will accept a point and a circle having the
center is (0,0) then print out the relative position of this point with the
circle. */

#include <stdio.h>

int check_point(double x, double y, double r);

int main(void)
{
    double x, y, r;
    
    do
    {
        printf("Enter x: \n");
        scanf("%lf", &x);

        printf("Enter y: \n");
        scanf("%lf", &y);

        printf("Enter r: \n");
        scanf("%lf", &r);
    } while (r < 0);

    int result = check_point(x, y, r);
    if (result == 0)
    {
        printf("The point is inside the circle");
    }

    else if (result == 1)
    {
        printf("The point is on the circle");
    }
    else
    {
        printf("The point is outside the circle");
    }
    return 0;
}

int check_point(double x, double y, double r)
{
    double d2 = x*x + y*y; // x^2 + y^2
    double r2 = r*r;     // r^2
    
    if (d2 < r2)   // inside
    {
        return 0;
    }
    
    else if (d2 == r2)  // on
    {
        return 1;
    }
    return -1;  // outside
}

