#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ROW 20
#define COLM 30

int main(void)
{
	int arr[ROW][COLM];
	char output[ROW][COLM+1];
	int row = 0;
	int colm = 0;
	FILE *fp;
	int i = 0;
	int *pi = arr;
	char ch;
	//get data from file
	if((fp=fopen("12.txt","r")) == NULL)
	{
		fprintf(stdout, "cannot open file 12.txt.\n");
		exit(0);
	}

	while(fscanf(fp,"%d", pi+i) == 1)
			i++;

	for(row = 0; row < ROW; row++)
	{
		for(colm = 0; colm < COLM; colm++)
		{
			char s[10];
			sprintf(s,"%1d",arr[row][colm]);
			switch(*s){
				case '0': ch = ' '; break;
				case '1': ch = '.'; break;
				case '2': ch = '\''; break;
				case '3': ch = ':'; break;
				case '4': ch = '~'; break;
				case '5': ch = '*'; break;
				case '6': ch = '='; break;
				case '8': ch = '%'; break;
				case '9': ch = '#'; break;
			}
			output[row][colm] = ch;
		}
			output[row][30] = '\0';
	}
	for(i = 0; i < ROW; i++)
		puts(output+i);
	return 0;
}
