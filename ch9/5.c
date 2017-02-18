#include <stdio.h>

void  larger_of(double *, double *);

int main(void)
{
	double a,b;
	printf("input 1st num:");
	scanf("%lf", &a);
	printf("input 2nd num:");
	scanf("%lf", &b);
	printf("before func: they are %.3f and %.3f\n", a, b);
	larger_of(&a, &b);
	printf("after func: they are %.3f and %.3f\n", a, b);
	return 0;
}

void  larger_of(double *a, double *b)
{
	double max;
	max = *a > *b ? *a : *b;
	*a = *b = max;
}
	
