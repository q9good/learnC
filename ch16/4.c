#include <stdio.h>
#include <time.h>

void time_delay(unsigned int);

int main()
{
	clock_t stepin, stepout;
	double duration;
	stepin = clock();
	time_delay(1000000);
	stepout = clock();
	duration = (stepout - stepin)/CLOCKS_PER_SEC;
	printf("Duration is %.5lf\n", duration);
	return;
}

void time_delay(unsigned int t)
{
	int i;
	for(i = 0; i < t; i++)
		;
}
