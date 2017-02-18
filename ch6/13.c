#include <stdio.h>
#define LEN 8

int main(void)
{
	int arr1[LEN], arr2[LEN];
	int i, j, k;
	for(i = 0;i < LEN;i++){
		printf("please input the %d number:", i+1);
		scanf("%d", arr1+i);
	}
	
	for(j = 1,arr2[0]= arr1[0]; j < LEN;j++){
		arr2[j] = arr2[j-1] + arr1[j];
	}

	for(k = 0;k < LEN; k++)
		printf("%5d", *(arr1+k));
		putchar('\n');
	
	for(k = 0;k < LEN; k++)
		printf("%5d", *(arr2+k));
		putchar('\n');
	
	return 0;
}
		
