#include <stdio.h>
#include <math.h>
#define WEIGHT_W (3.0*(pow(10,-23)))
int main()
{
	int quarts;
	printf("please input quarts of water:");
	scanf("%d", &quarts);
	printf("%d quarts water has  %f water molecule\n", quarts, \
		quarts*950/WEIGHT_W);
	return 0;
}

