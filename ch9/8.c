#include <stdio.h>

double power(double ,int);

int main(void)
{
	double base, res;
	int exp;
	printf("input the base and exp:");
	scanf("%lf %d", &base, &exp);
	res = power(base, exp);
	printf("%.3f exp %d is %.3f\n", base, exp, res);
	return 0;
}

double power( double base, int exp)
{
	int times= exp;
	double res = 1;
	if(times > 0){
		times--;
		return  base * power(base, times);
	}
	else if(times < 0){
		times++;
		return 1 / base *power(base, times);
	}
	else 
		return 1;
}
	
