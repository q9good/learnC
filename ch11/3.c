#include <stdio.h>
#define LEN 80

 getword(char *dst);

int main(void)
{
	char words[LEN];
	while(1){
		getword(words);
		puts(words);
	}
	return 0;
}

getword(char * dst)
{
	int ch;
	while( isspace(ch=getchar()))
		;
	*dst++ = ch;
	while (!isspace(ch=getchar()) && ch !=',')
		*dst++ = ch;	
	*dst = '\0';
	while( getchar()!='\n')
		;
}
		
