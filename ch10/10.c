#include <stdio.h>

#define ROW 5

void show_2d(double (*arr)[ROW],  int);
void double_2d(double arr[][ROW], int colm);

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

	show_2d(source, 3);
	double_2d(source, 3);
	show_2d(source, 3);
	return 0;
}

void show_2d(double (*arr)[ROW],  int colm)
{
	int i, j;

	for( i = 0 ; i < colm; i++){	
		for (j = 0; j < ROW; j++)
			printf("%-5.1f", *(*(arr + i) + j));
		putchar('\n');
		
	}
}

void double_2d(double arr[][ROW], int colm)
{
	int i, j;
	for (i = 0; i < colm; i++)
		for( j = 0; j < ROW; j++)
			*(*(arr+i)+j) *= 2;
}
