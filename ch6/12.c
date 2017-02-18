#include <stdio.h>
#include <math.h>
#define LEN 8

int main(void){
	int arr[LEN];
	int i;
	for(i = 0;i < LEN;i++)
		*(arr+i) = (int)(pow(2,i));
	i = 0;
	do{
		printf("arr[%d] = %d\n", i, arr[i]);
		i++;
	}while(i < LEN);
}
