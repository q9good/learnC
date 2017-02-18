#include <stdio.h>
int main()
{
	int count, sum, lim;

	printf("please input the num:");
	scanf("%d", &lim);
	count = 0;
	sum = 0;
	while ( count++ < lim)
	{
		sum += count;
	}
	printf("sum = %d\n", sum);
	return 0;
}
