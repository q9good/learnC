#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
	double base;
	int power;
	base = atof(argv[1]);
	power = atoi(argv[2]);
	printf("%-5.2lf 's %d square is %-5.2lf\n", 
		base, 	power,      pow(base,power));
	return 0;
}
						

