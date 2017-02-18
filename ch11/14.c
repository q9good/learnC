#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char str[]="-101";
	char *c = str;
	if( *c != '+' && *c != '-' &&  !isdigit(*c))
	{
		printf("error\n");
		return-1;
	}
	int num = 0;
	
	if(*str == '-' || *str == '+')
		c++;
	while( *c != '\0'){
		if(  !isdigit(*c))
		{
			printf("error\n");
			return-1;
		}
		num = num*10 + *c - '0';
		c++;
	}
	if(*str == '-')
		printf("%d\n", -1*num);
	else
		printf("%d\n", num);
	return 0;
}
		
