#include <stdio.h>

char strda = 'F';

int main(void)
{
	int i, j;
	for(i = 1; i < 7; i++){
		for(j = 0;j < i; j++){
			printf("%c",strda - j);
		}
		printf("\n");
	}
	return 0;
}
