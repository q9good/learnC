#include <stdio.h>
#define LEN 20

int main(void)
{
	char firstname[LEN];
	char surname[LEN];
	printf("please input firstname:");
	gets(firstname);
	printf("please input surname:");
	gets(surname);
	printf("Your name is %s %s\n", firstname, surname);
	return 0;
}
