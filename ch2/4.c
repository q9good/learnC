#include <stdio.h>

#define MSG1 "For he's a jolly good fellow!"
#define MSG2 "Which nobody can deny!"

void putstr1()
{
	printf("%s\n", MSG1);
}

void putstr2()
{
	printf("%s\n", MSG2);
}

int main(void)
{
	int i = 0;
	for( ; i < 3; i++)
		putstr1();
	putstr2();
	return 0;
}
