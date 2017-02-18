#include <stdio.h>

char * getnchar(char *, int len);

int main(void)
{
	int len;
	printf("please input the length of chars:");
	scanf("%d", &len);
	char str[len+1];
	char *check;
	check = getnchar(str, len);
	puts(str);
	return 0;
}

char * getnchar(char *src, int len)
{
	int i;
	int ch;
	while(isspace(ch=getchar()))
		;
	for ( i = 0; i < len; i++){	
		*(src+i) = ch; 
		ch = getchar();
	}
	*(src+i) = '\0';
	return src;
}
