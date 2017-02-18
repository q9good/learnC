#include <stdio.h>

#define ROW 3
#define COLM 5

void store(int row, int colm, double arr[row][colm]);
double average2d(int row, int colm, double arr[row][colm]);
double average(double arr[][COLM], int row);
double max(int row, int colm, double arr[row][colm]);
void show2d(int row, int colm, double arr[row][colm]);

int main(void)
{
	double stuff[ROW][COLM];
	double avg[ROW];
	int i;
	printf("input numbers for double arr\n");
	store(ROW, COLM, stuff);
	
	show2d(ROW, COLM, stuff);

	for( i = 0; i < ROW; i++){
		printf("the avg of %d row is %lf\n", 
				  i+1,   average(stuff, i));
	}

	printf("the avg of the whole arr is %lf\n", 
				average2d(ROW, COLM, stuff));
	printf("the max in the whole arr is %lf\n",
				max(ROW,COLM, stuff));

	return 0;
}


void store(int row, int colm, double arr[row][colm])
{
	int i, j;
	for( i = 0; i < row; i++){
		for( j = 0; j < colm; j++){
		   printf("input %d number of %d row:", j+1, i+1);
		   scanf("%lf", &arr[i][j]);
		}
	}
}

double average2d(int row, int colm, double arr[row][colm])
{
	int i, j;
	double sum2d = 0;
	for( i = 0; i < row; i++)
		for( j = 0; j < colm; j++)
			sum2d += *(*(arr+i)+j);
	return sum2d/(row*colm);
}

double average(double arr[][COLM], int row)
{
	int i;
	double sum = 0;
	for( i = 0; i < COLM; i++)
		sum += *(*(arr+row)+i);
	return sum/COLM;
}
	
double max(int row, int colm, double arr[row][colm])
{
	int i;
	int len = row*colm;
	double max;
	double *ptr = (double *)arr;
	for(i = 0, max = **arr; i < len; i++)
		if(ptr[i] > max)
			max = ptr[i];
	return max;
}

void show2d(int row, int colm, double arr[row][colm])
{
	int i, j;
	for( i = 0; i < row; i++){
		for( j = 0; j < colm; j++)
			printf("%-5.1f", *(*(arr+i)+j));
		putchar('\n');
	}
	putchar('\n');
}
	
