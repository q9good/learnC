#include <stdio.h>
#define LEN 20

int main(void)
{
	char firstname[LEN];
	char surname[LEN];
	char name[2*LEN];
	printf("please input firstname:");
	gets(firstname);
	printf("please input surname:");
	gets(surname);
	strcpy(name, firstname);
	strcat(name, surname);
	printf("\"%s\"\n",name);
	printf("\"%20s\"\n",name);
	printf("\"%-20s\"\n",name);
	printf("\"%s   \"\n",name);
	return 0;
}
