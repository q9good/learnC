#include <stdio.h>
#define BASE 10.0
#define BONUS 1.5
#define RT1 0.15
#define RT2 0.2
#define RT3 0.25

int main(void)
{
	double amount, tax, net;
	double workhour;
	printf("please input the workhour:");
	scanf("%lf", &workhour);
	printf("%f\n", workhour);
	amount = workhour*BASE +( workhour > 40 ? (workhour-40)*0.5 : 0);
	printf("%f\n", workhour > 40 ? (workhour-40)*0.5 : 0);
	if(amount >= 450){
			tax = (amount-450)*RT3 + 300*RT1 +150*RT2;
	}
	else if(amount >=300){
			tax =(amount-300)*RT2 + 300*RT1;
	}
	else
			tax = amount*RT1;
	printf("The amount of salary is %g\n", amount);
	printf("The tax is %g\n", tax);
	printf("The net salary is %g\n", amount-tax);
}
