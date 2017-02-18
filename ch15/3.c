#include <stdio.h>

int stoi(char *);
int cntbit(int );

int main(int argc, char *argv[])
{
	int len = 8*sizeof(int) + 1;
	int param;
	int openbit;

	param = stoi(argv[1]);
	openbit = cntbit(param);
	printf("%s has %d open bit\n", argv[1], openbit);
	return 0;
}

int stoi(char *str)
{	
	int num = 0;
	while(*str != '\0')
	{
		num = num*10 + (*str++ - '0');
	}
	return num;
}

int cntbit(int a)
{
	int cnt = 0;
	int i;
	for(i = 0; i < 8*sizeof(int); i++)
	{
		if((a & 0x01) == 1)
			cnt++;
		a >>= 1;
	}
	return cnt;
}

