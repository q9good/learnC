#include <stdio.h>
#define LEN 20

int main(void){
	char word[LEN];
	int len, i;
	puts("please input a word");
	scanf("%s", word);	
	len = strlen(word);
	for (i = len - 1;i >= 0;i--)
		putchar(word[i]);
	putchar('\n');
	return 0;
} 
