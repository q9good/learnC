#include <stdio.h>
#define LEN 4

int  is_within(char * src, char ch);

int main(void)
{
	char c = 'a';
	char *strs[LEN] = { "abce", "edba", "djle", "ecaer" };
	int dst;
	int i;
	for(i = 0; i < LEN; i++){
		dst = is_within(strs[i], c);
		printf("%d\n", dst);
	}
	return 0;
}

int  is_within(char * src, char ch)
{
	char * tmp = src;
	while( *tmp != '\0'){
		if ( *tmp == ch)
			return 1;
		else
			tmp++;
	}
	return 0;
}
