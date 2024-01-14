#include <stdio.h>

int main() {
    
	int n;
	float income, tf, ti, pa = 9000000, pd = 3600000;
    

    printf("Your income of this year: ");
    scanf("%f", &income);

    printf("Number of dependents: ");
    scanf("%d", &n);

    tf = 12 * (pa + n * pd);

    printf("Tax-free income: %.2f\n", tf);
    ti = income - tf;

    if (ti <= 0) 
	{
        printf("Taxable income = 0\n");
        printf("Income tax = 0\n");
    } 
	
	else if (ti > 0 && ti <= 5000000) 
	{
        printf("Taxable income = %.2f\n", ti);
        printf("Income tax = %.2f\n", ti * 5 / 100);
    } 
	
	else if (ti > 5000000 && ti <= 10000000) 
	{
        printf("Taxable income = %.2f\n", ti);
        printf("Income tax = %.2f\n", 5000000 * 5 / 100 + (ti - 5000000) * 10 / 100);
    } 
	
	else if (ti > 10000000 && ti <= 18000000) 
	{
        printf("Taxable income = %.2f\n", ti);
        printf("Income tax = %.2f\n", 5000000 * 5 / 100 + 5000000 * 10 / 100 + (ti - 10000000) * 15 / 100);
    } 
	
	else 
	{
        printf("Taxable income = %.2f\n", ti);
        printf("Income tax = %.2f\n", 5000000 * 5 / 100 + 5000000 * 10 / 100 + 8000000 * 15 / 100 + (ti - 18000000) * 20 / 100);
    }

    return 0;
}