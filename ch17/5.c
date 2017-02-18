#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void)
{
	Stack buf;
	char str[MAXSTACK];
	Item temp;
	Item *it = str;
	printf("please input str:");
	scanf("%s", str);
	InitializeStack(&buf);
	while(*it != '\0')
	{
		Push(*it, &buf);
		it++;
	}
	while(Pop(&temp, &buf))
		putchar(temp);
	putchar('\n');
	puts("Bye.");
}
