#include <stdio.h>
#define COLM 3
#define ROW 5

void store_set(double arr[][ROW], int colm);
double mean_vec(double *vector, int len);
double findmax(double arr[][ROW], int colm);

int main(void)
{
	double arr[COLM][ROW];
	double avg[COLM];
	int i;

	printf("please input 1st number set:");
	store_set(arr, 0);
	
	printf("please input 2nd number set:");
	store_set(arr, 1);
	
	printf("please input 3rd number set:");
	store_set(arr, 2);
	for (i = 0; i < COLM; i++){
		*(avg + i) = mean_vec((double *)(arr+i), ROW);
		printf("the avg of %d colm is %lf\n", i+1, avg[i]);
	}
	printf("the avg of arr is %lf\n", mean_vec(avg, COLM));
	printf("the max of it is %lf\n", findmax(arr,COLM));
	
	return 0;
}


void store_set(double arr[][ROW], int colm)
{
	int i;
	for(i = 0; i < ROW; i++){
		printf("please input %d number:", i+1);
		scanf("%lf", *(arr + colm) + i);
	}
}

double mean_vec(double *vector, int len)
{
	int i;
	double sum = 0;
	for ( i = 0; i < len; i++){
		sum += *(vector+i);
	}
	return (double)(sum/len);
}

double findmax(double arr[][ROW], int colm)
{
	int i, j;
	double max = 0;
	for(i = 0; i < colm; i++)
		for( j = 0; j < ROW; j++)
			if(arr[i][j] > max)
				max = arr[i][j];
	return max;
}








