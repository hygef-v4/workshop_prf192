/*When user chooses 1: User will enter values describing a quadratic equation
then the program will print out its solution if it exists.
- When user chooses 2: User will enter his/her deposit ( a positive number), yearly
rate ( a positive number but less than or equal to 0.1), number of years ( positive
integer), then the program will print out his/her amount after this duration.*/
#include <stdio.h>
#include <stdbool.h>
#include <math.h>  

void quadratic();
void deposit();
int main(void)
{
    int n;
    int choice;
    // menu 
    do
    {
        printf("1- Solve quadratic equation\n");
        printf("2- Bank deposit \n");
        printf("3- Quit\n");
        printf("Select an operation: ");
        scanf("%d", &choice);  

        switch (choice)     // user choice 
        {
        case 1:
            quadratic();
            break;
            
        case 2:
            
            deposit();
            break;
        }
    } while (choice > 0 && choice < 3); 

    return 0;
}

void quadratic()
{
    float a, b, c, delta;
    printf("\nax^2 + bx + c = 0 (a != 0)\n");  
	printf("\nEnter a, b, c: ");
    scanf("%f%f%f", &a, &b, &c);
    
    	if (a != 0) 
        {
		delta = b*b - 4*a*c;   // delta 
		// check condition
        if (delta == 0)
			printf("\nPhuong trinh co nghiem kep x1 = x2 = %f\n", -b/(2*a));
		else if ( delta >= 0)
			printf("\nPhuong trinh co hai nghiem phan biet: x1 = %f, x2 = %f\n", (-b+sqrt(delta))/(2*a), (-b-sqrt(delta))/(2*a));
		else printf("\nPhuong trinh vo nghiem!\n");
	}
	else printf("\nError: a < 0\n");

}
void deposit()
{
    float deposit, rate, result;
    int year;
	do 
    {
	printf("\nEnter your deposit: ");
	scanf("%f", &deposit);
    } while (deposit <= 0);

	do {
	printf("\nEnter yearly rate (between 0.1 and 1.0): ");
	scanf("%f", &rate);
    } while (rate <= 0 || rate >= 1);

    do {
	printf("\nEnter number of year: ");
	scanf("%d", &year);
    } while (year <= 0);  
    result = deposit*pow(1+rate, year);     // calculate deposit 
    result= round(result * 1000) / 1000;    // round to 3 decimal point
    printf("\nYour amount after this duration: %.3f\n", result); 

}
