#include <stdio.h>
#include <ctype.h>

double operator(double num1, double num2, char operator);

int main(void)
{
    double num_1;
    double num_2;
	char op; 
	
	printf ("Enter num 1\n");
	scanf("%lf", &num_1);
	
	printf ("Enter num 2\n");
	scanf("%lf", &num_2);
	
	printf ("Enter operator\n");
	scanf(" %c", &op);
	
	double result = operator(num_1, num_2, op);

    if (result != -1)  // chi in ra ket qua khi mau so !=0 
    {
        printf("Result is: %.2lf", result);
    }
	
    return 0;
}

double operator(double num1, double num2, char operator)
{
	double result = 0;
	switch(operator)
	{
		case '+':
			result = num1 + num2;
			break;
			
		case '-':
			result = num1 - num2;
			break;
			
		case '*':
			result = num1 * num2;
			break;
		
		case '/':
			if (num2 == 0)
			{
			    printf("Num 2 cannot = 0\n");
                return -1;  // neu loi thi in ra -1
			}
			else
			{
				result = num1 / num2;
			}
			break;
		
		default:
			printf("Invalid operator!");
            return -1;
	}
	return result;
}