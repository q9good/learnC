#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define HTMIN 60

int main()
{
	int mins;
	div_t result;
	printf("please input minutes:");
	while((scanf("%d", &mins)) && mins > 0){
		result = div(mins, HTMIN);
		printf("%d minutes means %d hours and %d mins\n", \
			mins, result.quot, result.rem);
		printf("please input minutes:");
	}
	return 0;
}
