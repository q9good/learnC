#include <stdio.h>

int findmax(int [], int);

int main(void)
{
	int arr[5] = {1, 2, 9, 4, 5};
	int max =findmax(arr, 5);
	printf("the max one is %d\n", max);
	return 0;
}

int findmax(int arr[], int len)
{
	int i;
	int max;
	for(i = 0, max = 0; i < len; i++)
		if(arr[i] > arr[max])
			max = i;
	return max+1;
}
