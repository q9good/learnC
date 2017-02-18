#include <stdio.h>
#include <math.h>

int IsPrime(int n);

int main()
{
	int in;
	int i;
	printf("please input a num:");
	scanf("%d", &in);
	for (i = 1; i < in; i += 2){
		if (IsPrime(i))
			printf("%8d", i);
		if(i%8 == 0)
			putchar('\n');
	}
	return 0;
}

int IsPrime(int in)
{
	int lim;
	lim = sqrt(in) + 1;
	int i;
	for( i = 2;i < lim; i++){
		if(in % i == 0)
			return 0;
	}
	return 1;
}
