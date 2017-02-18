#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int ch, let, word;
	let = word = 0;
	while ( (ch=getchar()) != EOF){
		if(ispunct(ch) || ch == ' ')
			word++;
		else
			let++;
	}
	printf("input %3d letters , %3d words\n", let, word);
	printf("in general, every word has %3d letter in aver",let/word);
	return 0;
}
