#include <stdio.h>
int main()
{
	//putchar(getchar());
	int ascii;
	printf("input a ascii value:");
	scanf("%d", &ascii);
	putchar(ascii);
	printf("\n%c\n",ascii);
	return 0;
}

