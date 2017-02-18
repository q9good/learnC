#include <stdio.h>

int main(void)
{
	float fund = 100;
	int i = 0;
	do{
		fund *= 1.08;
		fund -= 10;
		i++;
	}while(fund >= 0);
	
	printf("after %d years, Chuckie will lose all money\n", i);
	return 0;
}
