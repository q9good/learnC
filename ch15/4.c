#include <stdio.h>

int stoi(char *);
int apptbit(int, int );

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Usege: %s an-integer-value a-bit-pos.\n",
							argv[0]);
		return -1;
	}
	int param;
	int openbit;

	param = stoi(argv[1]);
	openbit = apptbit(param, stoi(argv[2]));
	printf("the %d bit of integer %d is %d\n", stoi(argv[2]), param, openbit);
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

int apptbit(int num, int pos)
{
	int i;
	int mask = 0x01;
	for(i = 0; i < pos - 1; i++)
		mask <<= 1;
	if((num & mask) != 0)
		return 1;
	else
		return 0;
}

