#include <stdio.h>
void to_base_n(unsigned int, unsigned int);

int main(void)
{
	unsigned int number, base;
	printf("Enter an interger and base:\n");
	while(scanf("%u %u", &number, &base) == 2){
		printf("base %u equivalent:", number);
		to_base_n(number, base);
		putchar('\n');
		printf("Enter an interger and base:\n");
	}
	return 0;
}

void to_base_n(unsigned int num, unsigned int base)
{
	int r;
	r = num % base;
	if( num >= base)
		to_base_n(num/base, base);
	putchar('0'+r);
}	
