#include <stdio.h>

char *src[] = { "astronomy", "astounding", 
		"astrophysics", "sound",
		"astro", "devilmaycry"};

char *mstrncpy(char *s1, const char *s2, int n);

int main(void)
{
	int i;
	char dst[20];
	for(i = 0; i < 6; i++)
		puts(mstrncpy(dst, src[i], i+4));
	return 0;
}

char *mstrncpy(char *s1, const char *s2, int n)
{
	int i;
	char *dst = s1;
	for( i = 0; i < n; i++){
		if(*s2 != '\0')
			*dst++ = *s2++;
		else
			break;
	}
	*dst = '\0';
	return s1;
}
	
