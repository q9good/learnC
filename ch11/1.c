#include <stdio.h>
void getnchar(char arr[], int len);

int main(void)
{
	int len;
	printf("please input the length you want to store:");
	scanf("%d", &len);
	getchar();
	char line[len+2];
	getnchar(line, len);
	puts(line);
	return 0;
}

void getnchar(char arr[], int len)
{
	int i;
	for(i = 0; i < len; i++)
		arr[i] = getchar();
	arr[i] = '\0';
}

