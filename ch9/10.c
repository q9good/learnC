#include <stdio.h>

int Fibonacci(int);

int main(void)
{
	int n;
	printf("input the num of array:");
	scanf("%d", &n);
	printf("The %d number in Fibonacci array is :%d\n", n, Fibonacci(n));
	return 0;
}

int Fibonacci(int n)
{
	int i,  sum;
	int fir, sec;
	fir = sec = 1;
	if (n < 1){
		printf("please input a positive num!\n");
		return -1;
	}
	else if(n == 1 || n == 2)
		return 1;
	else{
		for (i = 2; i < n; i++){
			sum = fir + sec;
			fir = sec;
			sec = sum;
		}
		return sum;
	}
}
