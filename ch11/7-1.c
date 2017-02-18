#include <stdio.h>

char *src[] = { "asaassastronomy", "aastounding", 
		"astrophysics", "sound",
		"astro", "devilmaycry",
		"asoastejlr"};

char *string_in(const char *s1, const char * s2);

int main(void)
{
	char cmp[]="ast";
	int i;
	char *dst;
	for(i = 0; i < 7; i++){
		dst = string_in(src[i], cmp);
		if( dst != NULL)
			puts(dst);
		else
			puts("not found!");
	}
	return 0;
}	

char *string_in(const char *p1, const char * p2)
{
	char *p1_save = p1, *p2_save = p2;
if(*p1 == '\0' || *p2 == '\0') return NULL;
while(1)
{
if(*p1 == *p2)
{
if(*++p2 == '\0') return p1_save;
if(*++p1 == '\0') return NULL;
}
else
{
if(*++p1 == '\0') return NULL;
p1_save = p1;
p2 = p2_save;
}
}
}
