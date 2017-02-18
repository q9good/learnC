#include <stdio.h>
#include <math.h>

int main(void){
	float num1, num2;
	printf("please input 2 float numbers:");
	while(scanf("%f %f", &num1, &num2)==2){
		printf("(%f - %f)/(%f*%f) = %f\n", num1, num2, num1, \
				num2, (num1-num2)/(num1*num2));
	printf("please input 2 float numbers:");
	}
	return 0;
}
