#include <stdio.h>
#define ALPHA 'A'

int main(void){
	int i, j, k, dist;
	char letter;
	printf("please input a uppercase character:");
	letter = getchar();
	dist = letter - ALPHA;
	for (i = 0;i < dist + 1; i++){
		printf("%*c",dist-i+1, ALPHA); 	
		j = 1;
		while(j <= i){
			printf("%c", ALPHA+j);
			j++;
		}
		for( ;j > 1; j--)
			printf("%c", ALPHA+j-2);
		putchar('\n');
	}
	return 0;
}
			
