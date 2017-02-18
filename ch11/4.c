#include <stdio.h>
#define LEN 4

char * strchar(char * src, char ch);

int main(void)
{
	char c = 'a';
	char *strs[LEN] = { "abce", "edba", "djle", "ecaer" };
	char *dst;
	int i;
	for(i = 0; i < LEN; i++){
		dst = strchar(strs[i], c);
		if(dst != NULL)
			puts(dst);
	}
	return 0;
}

char * strchar(char * src, char ch)
{
	char * tmp = src;
	while( *tmp != '\0'){
		if ( *tmp == ch)
			return tmp;
		else
			tmp++;
	}
	return NULL;
}
