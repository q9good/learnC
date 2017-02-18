#include <stdio.h>
#define LEN 255

int main(void)
{
	char line[LEN];
	int i=0;
	puts("please input a line.");
	while(scanf("%c",line+i)==1
		&& *(line+i)!=EOF
		&& *(line+i)!='\n'){
		i++;
	}
	
	for( ;i >= 0;i--)
		putchar(line[i]);
	return 0;
}
