#include <stdio.h>
#define SHOWSUMS(a,b) printf("The sums of the squares from %d to %d \
is %d\n",a*a, b*b, a*a+b*b) 

int main(void){
	int upper, lower;
	printf("please input lower and upper integer limits:");
	while (scanf("%d %d", &lower, &upper)==2
		&& lower < upper){
		SHOWSUMS(lower,upper);
		printf("Enter next set of limits:");
	}
	puts("Done.");
}
