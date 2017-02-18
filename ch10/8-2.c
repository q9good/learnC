#include <stdio.h>

#define ROW 5

void show_2d(int colm, int row, double arr[colm][row]);
void copy_2d(int colm, int row, double src[colm][row],double dst[colm][row]);

int main(void)
{
	int m,n;
	m = 3;
	n = ROW;

	double source[3][ROW] = {
				{1.1, 2.2, 3.3, 4.4, 5.5},
				{6.6, 7.7, 8.8, 9.9, 10.1},
				{1.1, 1.2, 1.3, 1.4, 1.5}
				};
	double target[m][n];
	printf("before copy arr, target is\n");
	show_2d(m, n, target);
	copy_2d(m, n, source, target);
	printf("after copy arr, target is\n");
	show_2d(m, n, target);

	return 0;
}

void show_2d(int colm, int row, double arr[colm][row])
{
	int i, j;

	for( i = 0 ; i < colm; i++){	
		for (j = 0; j < row; j++)
			printf("%-5.1f", *(*(arr + i) + j));
		putchar('\n');
		
	}
}

void copy_2d(int colm, int row, double src[colm][row],double dst[colm][row])
{
	int i, j;

	for( i = 0 ; i < colm; i++){	
		for (j = 0; j < row; j++){
			*(*(dst+i)+j) = *(*(src+i)+j);
		}
	}
}
