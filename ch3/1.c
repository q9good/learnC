#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	int limits = INT_MAX;
	float upper = FLT_MAX;
	float down = FLT_MIN;
	printf("the max int is %d in hex:0x%x\n", limits, limits);
	printf("beyond the max is %d in hex:0x%x\n", (1 +limits), (1 +limits));
	printf("the max float is %f in hex:0x%x\n", upper, upper);
	printf("beyond the max is %f in hex:0x%x\n",(upper + 1.0),(upper + 1.0));
	printf("the min float is %f in hex:0x%x\n", down, down);
	printf("beyond min float is %f in hex:0x%x\n", (down - 1.0), (down - 1.0));
}
