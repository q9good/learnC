#include <stdio.h>
#include <string.h>

#define MAX 10

void showstr(char *strings[], int len);
int init(char *strings[], int len);

char input[MAX][90];

int main(void)
{
	char *str[MAX];
	int ch, cnt;
	cnt = init(str,MAX);
	showstr(str, cnt);
		
	return 0;
}

int init(char *strings[], int len)
{
	int i = len;
	int cnt = 0;
	while( cnt < len && gets(input[cnt]) != NULL
			 && input[cnt][0] != '\0'){
		strings[cnt] = input[cnt];
		cnt++;
	}
	
	return cnt;
}

void showstr(char *strings[], int len)
{
	int i;
	for( i = 0; i < len; i++)
		puts(strings[i]);
}
