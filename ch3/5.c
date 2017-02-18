#include <stdio.h>
#include <math.h>
#define SECOND (3.156*(pow(10,7)))
int main()
{
	int age;
	printf("please input your age:");
	scanf("%d", &age);
	printf("%d years means %f second\n", age, SECOND*age);
	return 0;
}

