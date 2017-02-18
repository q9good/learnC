#include <stdio.h>

int main(void)
{
	char ch;
	int i = 0;
	while((ch=getchar()) != EOF && ch != '#'){
		printf("%c %d\t", ch, ch);	
		i++;
		if( i%8 == 0){
			putchar('\n');
			i = 0;
		}
	}
	return 0;
}
