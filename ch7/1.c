#include <stdio.h>

int main(void)
{
	char ch;
	int blank, enter, other;
	blank = enter = other = 0;
	while((ch=getchar()) != EOF && ch != '#'){
		switch(ch)
		{
			case ' ':
			case '\t':
				blank++;
				break;
			case '\n':
				enter++;
				break;
			default:
				other++;
				break;
		}
	}
	printf("numbers of blank:%d\n", blank);
	printf("numbers of enter:%d\n", enter);
	printf("numbers of others:%d\n", other);
	return 0;
}
