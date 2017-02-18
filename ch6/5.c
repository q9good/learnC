#include <stdio.h>

int main(void){
	int min, max, j;
	printf("please input the range(seperate them by space):");
	scanf("%d %d", &min, &max);
	for (j = min; j < max;j++){
		printf("%10d %10d %10d\n", j, j*j, j*j*j);
	}
	return 0;
}	
