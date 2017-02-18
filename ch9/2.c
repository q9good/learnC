#include <stdio.h>

void chline (char, int, int);

int main(void)
{
	char ch;
	int i, j;
	printf("please input a character:");
	ch = getchar();
	while(getchar() != '\n');
	printf("input put it in which row:");
	scanf("%d", &i);
	printf("input put it in which column:");
	scanf("%d", &j);
	chline(ch, i, j);
	putchar('\n');
	return 0;
}
	
void chline(char ch, int i, int j)
{
	int m, n;
	m = 0;
	while ( m+1 < i){
		putchar('\n');
		m++;
	}
	n = 0;
	while ( n+1 < j){
		putchar(' ');
		n++;
	}
	putchar(ch);
}
