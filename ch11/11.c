#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	int words = 0;
	int upper = 0;
	int lower = 0;
	int number = 0;
	int punc = 0;
	char ch;
	int inword;
	while((ch=getchar()) != EOF){
		if(isupper(ch)){
			upper++;
			inword = 1;
		}
		else if(islower(ch)){
			lower++;
			inword = 1;
		}
		else if(isspace(ch)){
			punc++;
			if(inword == 1){
				words++;
				inword = 0;
			}
		}
		else if(ispunct(ch)){
			punc++;	
			if(inword == 1){
				words++;
				inword = 0;
			}
		}
		else if(isdigit(ch)){
			number++;
			inword = 1;
		}
		else 
			continue;
	}
	printf("%2d upper alpha\n", upper);
	printf("%2d lower alpha\n", lower);
	printf("%2d words\n", words);
	printf("%2d punctual\n", punc);
	printf("%2d digits\n", number);
	return 0;
}
