#include <stdio.h>

int main()
{
	int ch, cnt;
	cnt = 0;
	while ((ch=getchar()) && ch != EOF){
		cnt++;
	}
	printf("input %d characters\n", cnt);
}
