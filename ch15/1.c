#include <stdio.h>
#include <string.h>
#include <math.h>

int bstoi(char *);
int checkbs(char *);

int main(void)
{
	char bin_str[8*sizeof(int) + 1];
	printf("Enter binarys and see them in interger.\n");
	while(scanf("%s", bin_str) == 1)
	{
		if(checkbs(bin_str) == -1)
		{
			printf("please enter 0 or 1!\n");
		}
		else
		{
			printf("%s is %d\n", bin_str, bstoi(bin_str));
		}
	}
	puts("Bye!");

	return 0;
}

int checkbs(char *str)
{
	int len;
	int i;
	len = strlen(str);
	for(i = 0;i < len; i++, str++)
		if( *str != '0' && *str != '1')
			return -1;
	return 0;
}

int bstoi(char *bstr)
{
	int inter = 0;
	int i, len;
	len = strlen(bstr);
	char *ps = bstr + len - 1;
	for(i = 0; i < len; i++,ps--)
	{
		inter += (*ps - '0')*(0x01<<i);
	}
	return inter;
}
