#include <stdio.h>

char * getnchar(char *src, int len);

int main(void)
{
	int len;
	printf("please input the length of chars:");
	scanf("%d", &len);
	char str[len+1];
	getnchar(str, len);
	puts(str);
	return 0;
}

char * getnchar(char *src, int len)
{
	int ch;
	int i;
	while( isspace(ch = getchar()))
		;
	for( i = 0; i < len; i++){
		if( isspace(ch)){
			*(src+i) = '\0';
			return src;
		}
		else
			*(src + i) = ch;

		ch = getchar();
	}
	*(src+i) = '\0';
	return src;
}
			 
