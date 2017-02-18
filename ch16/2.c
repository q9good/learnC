#include <stdio.h>

#define HARMEAN(a,b)   1/(((1/(a)) + (1/(b)))/2 )

int main(void)
{
	float a, b, c;
	a = 2, b = 4;
	c = HARMEAN(a,b);
	printf("%f", c);
	return 0;
}
