#include <stdio.h>
#define LEN 20

int main(void)
{
	char firstname[LEN];
	char surname[LEN];
	int flen, slen;
	printf("please input firstname:");
	gets(firstname);
	flen = strlen(firstname);
	printf("please input surname:");
	gets(surname);
	slen = strlen(surname);
	printf("%s %s\n", firstname, surname);
	printf("%*d %*d\n", flen, flen, slen, slen);
	printf("%s %s\n", firstname, surname);
	printf("%-*d %-*d\n", flen, flen, slen, slen);
	return 0;
}
