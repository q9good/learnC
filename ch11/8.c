#include <stdio.h>
#include <string.h>

#define LEN 30

char * reverse(char *dst, char *src);

int main(void)
{
	char *src[] = { "cba", "nretxe", "tsonc"};
	char dst[LEN];

	int i;
	for(i = 0; i < 3; i++){
		if(reverse(dst,src[i]))
			puts(dst);
		else
			puts("failed");
	}
	return 0;
}
	
char * reverse(char *dst, char *src)
{
	int l2 = strlen(src);
	char *tail = src + l2 -1;
	char *head = dst;
	while( tail >= src)
		*dst++ = *tail--;
	*dst = '\0';
	return head;
}
