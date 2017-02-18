#include <stdio.h>

int main(void)
{
	char ch;
	int dot = 0;
	printf("please input a character:");
	while(1){
		scanf("%c", &ch);
		if( ch == '#')
			break;
		else if(ch == '.'){
			printf("!!"); 
			dot++;
			continue;
		}
		else{
			putchar(ch);
			continue;
		}
	}
	printf("it has exceute %d times replace\n", dot);
	return 0;
}
