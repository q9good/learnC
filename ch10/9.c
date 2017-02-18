#include <stdio.h>

#define LEN 4

void show_vec(int *, int);
void add_vec(int *, int *, int *, int);

int main(void)
{
	int arr1[LEN] = {2, 4, 5, 8};
	int arr2[LEN] = {1, 0, 4, 6};
	int arr3[LEN];
	
	show_vec(arr3, LEN);
	
	add_vec(arr1, arr2, arr3, LEN);
	show_vec(arr3, LEN);
	return 0;
}

void show_vec(int *arr, int len)
{
	int i;
	for( i = 0; i < len; i++)
		printf("%-4d", *(arr+i));
	putchar('\n');
}

void add_vec(int *src1, int *src2, int *dst, int len)
{
	int i;
	for ( i = 0; i < len; i++)
		*(dst+i) = *(src1+i) + *(src2+i);
}
