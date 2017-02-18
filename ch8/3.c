#include <stdio.h>
#include <ctype.h>

int main()
{
	int ch, upper, lower;
	upper = lower = 0;
	while ((ch = getchar()) != EOF){
		if (isalpha(ch)){
			if(isupper(ch))
				upper++;
			else
				lower++;
		}
	}
	printf("input %d upper letters and %d lower letters\n", \
					upper, lower);
	return 0;
}	
