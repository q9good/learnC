#include <stdio.h>
#include <ctype.h>

void check_alp(char);

int main(void)
{
	char ch;
	while( (ch=getchar()) != EOF){
		check_alp(ch);
	}
	return 0;
}

void check_alp(char ch)
{
	int tmp;
	if(isalpha(ch)){
		tmp = tolower(ch);
		printf("%c is %d\n", ch, tmp -'a'+1);
	}
	else
		printf("-1\n");
}
