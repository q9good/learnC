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

char *string_in(const char *s1, const char * s2)
{
	char *s = s1;
	char *t = s2;
	int i = 0;
	while( *s != '\0'){
		if( *s == *s2){
			while( *t != '\0'){
				if( *t != *(s+i)){
					t = s2;
					i = 0;
					break;
				}
				else{
					t++;
					i++;
				}
			}
			if( *t == '\0')
				return s;
			else
				s++;
		}
		else
			s++;
	}
	return NULL;
}
