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

int delspace(char *line)
{
	char *cp = line;
	int i = 0;
	while( *line != '\0'){
		if( isspace(*line)){
			cp = line ;
			while(isspace(*cp))
				cp++;
			while( *cp != '\0'){
				*(line + i) = *cp++;
				i++;
			}
			*(line+i) = *(cp);
			i = 0;
		}
		line++;
	}
	*line = '\0';
	return 0;
}
