#include <stdio.h>
double min(double, double);

int main(void)
{
	double x, y;
	printf("please input two float numbers:");
	scanf("%lf %lf", &x, &y);
	printf("the min value between %lf and %lf is %lf\n",
				x, y, min(x,y));
	return 0;
}

double min(double x, double y)
{
	return x > y ? y : x;
}
