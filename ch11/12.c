#include <stdio.h>
 
int main(int argc, char *argv[])
{
	int i = argc -1;
	while( i > 0){
		printf("%s ", argv[i]);
		i--;
	}
	putchar('\n');
	return 0;
}
