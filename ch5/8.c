#include <stdio.h>

void Temperatures(double);

int main(void)
{
 	const double factor = 1.8;
	const double offset = 32.0;
	const double kel = 273.16;
	double farh;
	printf("please input fahrenheit degree:");
	while (scanf("%lf", &farh)==1){
		Temperatures(farh);
		printf("please input fahrenheit degree:");
	}
	return 0;
}

void Temperatures(double farh)
{
	double cels, kelv;
	cels = farh * factor + offset;
	kelv = cels + kel;
	printf("%.2lf Fahrenheit = %.2lf Celsius = %.2lf Kelvin\n", \
		farh, cels, kelv);
}
