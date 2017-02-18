#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 20

void randomPrint(int *, int , int);

int main(int argc, char *argv[])
{
	int i, arr[LEN], dice;
	for(i = 0; i < LEN; i++)
	{
		arr[i] = (i+1)*i;
	}

	dice = atoi(argv[1]);
	randomPrint(arr, LEN, dice);
	return 0;
}

void randomPrint(int *arr, int len, int dice)
{
	int cnt = 0, printed[dice];
	int roll, done, i;
	srand((unsigned int)time(0));	
	for(	; cnt < dice ;	)
	{
		roll = rand()%len ;
		if(cnt == 0)
		{
			printf("%d element: %d\n", cnt+1, arr[cnt]);
			for(i = 0; i < dice; i++)
				printed[i] = roll;
			cnt++;
			done = 0;
		}
		else
		{
			for(i = 0; i < dice; i++)
				if(roll == printed[i])
				{
					done = 1;
					break;
				}
			if(done == 1)
				continue;
			else
			{
				printf("%d element: %d\n", cnt+1, arr[cnt]);
				printed[cnt++] = roll;
				done = 0;
			}
		}
	}
}
