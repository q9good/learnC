#include <stdio.h>

int main(void)
{
	int ch, i;
	for (i=0;(ch=getchar())!=EOF;i++){
		if( ch == ' ' || ch == '\t' || ch =='\n')
			printf("\%-4c", ch);
		else
			printf("^%-4c", ch);	
		printf("%4d", ch);
		if(i%8 == 0)
			putchar('\n');
	}
	return 0;
}
	
