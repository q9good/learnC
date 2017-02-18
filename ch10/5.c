#include <stdio.h>

int dif(int [], int);

int main(void)
{
	int arr[5] = {1, 2, 9, 4, 5};
	int max =dif(arr, 5);
	printf("the dif is %d\n", max);
	return 0;
}

int dif(int arr[], int len)
{
	int i;
	int max, min;
	max = min = arr[0];
	for(i = 0 ; i < len; i++){
		if(arr[i] > max)
			max = arr[i];
		else if(arr[i] < min)
			min = arr[i];
	}
	return max-min;
}
