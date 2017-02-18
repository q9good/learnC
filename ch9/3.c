#include <stdio.h>

void chline (char, int, int);

int main(void)
{
	char ch;
	int i, j;
	printf("please input a character:");
	ch = getchar();
	while(getchar() != '\n');
	printf("input numbers in each line:");
	scanf("%d", &i);
	printf("input how many lines:");
	scanf("%d", &j);
	chline(ch, i, j);
	return 0;
}
	
void chline(char ch, int i, int j)
{
	int m, n;
	for(n = 1;n <= j;n++){
		for(m = 1; m <= i; m++)
			putchar(ch);
		putchar('\n');
	}
}
