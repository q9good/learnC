#include <stdio.h>
#define ALPHA 26

int main()
{
	char arr[ALPHA];
	char a ='a';
	int i;
	for (i = 0; i < 26; i++)
	{
		arr[i] = a + i;
		printf("%c	",arr[i]);
	}
	return 0;
}
	
