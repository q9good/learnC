#include <stdio.h>
#include <string.h>

#define LEN 90

int delspace(char *line);
char * s_gets(char *dst, int n);

int main(void)
{
	char line[LEN];
	while(s_gets(line, LEN)){
		if(!delspace(line))
			puts(line);
	}
	return 0;
}

char * s_gets(char *dst, int n)
{
	int ch;
	int i;
	char *ret = dst;
	while((ch=getchar()) != '\0' && n--)
	{
		if( ch != '\n')
			*dst++ = ch;
		else
			break;
	}
	*dst = '\0';
	if( strchr(ret, ' ') == ret)
		return NULL;
	else
		return ret;
}

int delspace(char *s)
{
char * pos;
while (*s) /* or while (*s != '\0') */
{
if (*s == ' ')
{
pos = s;
do
{
*pos = *(pos + 1);
pos++;
} while (*pos);
}
else
s++;
}
}

