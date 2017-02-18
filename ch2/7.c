#include <stdio.h>

void one_three();
void two();

int main()
{
	puts("starting now:");
	one_three();
	puts("done!");
	return 0;
}
	
void one_three()
{
	puts("one");
	two();
	puts("three");
}

void two()
{
	puts("two");
}
