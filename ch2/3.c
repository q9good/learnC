#include <stdio.h>
int yr2dy(int);
int age;

int main(void)
{
	printf("please input how old are you:");
	scanf("%d",&age);
	printf("%d years means %d days", age, yr2dy(age));
	return 0;
}

int yr2dy(int year)
{
	return (365*year);
} 
