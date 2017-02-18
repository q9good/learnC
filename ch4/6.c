#include <stdio.h>
#include <float.h>

int main()
{
	double a =(1.0/3.0);
	float b =(1.0/3.0);
	printf("double a is %.4lf float b is %.4f\n", a ,b);
	printf("double a is %.12lf float b is %.12f\n", a ,b);
	printf("double a is %.16lf float b is %.16f\n", a ,b);
	printf("FLT_DIG is %d and DBL_DIG is %d\n", FLT_DIG, DBL_DIG);
	return 0;
}
	
