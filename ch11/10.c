#include <stdio.h>
#include <string.h>

#define MAX 10

void show_menu();
void showstr(char *strings[], int len);
void sort_asc(char *strings[], int len);
void sort_len(char *strings[], int len);
void sort_word(char *strings[], int len);
int wordlen(char *s);


int main(void)
{
	char input[MAX][90];
	char *str[MAX];
	int ch;
	int cnt = 0;
	printf("Input up to %d lines.\n", MAX);
	while( cnt < MAX && gets(input[cnt]) != NULL
			 && input[cnt][0] != '\0'){
		str[cnt] = input[cnt];
		cnt++;
	}
	show_menu();
	while( (ch=getchar()) != 'q'){
		switch(ch){
			case 'a':showstr(str,cnt);
				break;
			case 'b':sort_asc(str,cnt);
				showstr(str,cnt);
				break;
			case 'c':sort_len(str,cnt);
				showstr(str,cnt);
				break;
			case 'd':sort_word(str,cnt);
				showstr(str,cnt);
				break;
			default:
				show_menu();
				break;
		}
	}
	return 0;
}


void show_menu()
{
	printf("****************************************\n");
	printf("a: put the origin\n");
	printf("b: sort the strings by ASCII\n");
	printf("c: sort the strings by length\n");
	printf("d: sort the strings by the first word\n");
	printf("q:quit\n");
	printf("****************************************\n");
	printf("your choice:");
}


void showstr(char *strings[], int len)
{
	int i;
	for( i = 0; i < len; i++)
		puts(strings[i]);
}

void sort_asc(char *strings[], int len)
{
	char *temp;
	int head, seek;
	for(head = 0; head < len -1; head++)
		for(seek = head + 1; seek < len; seek++)
			if(strcmp(strings[head], strings[seek]) > 0)
			{
				temp = strings[head];
				strings[head] = strings[seek];
				strings[seek] = temp;
			}
}

void sort_len(char *strings[], int len)
{
	char *temp;
	int head, seek;
	for(head = 0; head < len -1; head++)
		for(seek = head + 1; seek < len; seek++)
			if(strlen(strings[head]) > 
				strlen(strings[seek]))
			{
				temp = strings[head];
				strings[head] = strings[seek];
				strings[seek] = temp;
			}
}
void sort_word(char *strings[], int len)
{
	char *temp;
	int head, seek;
	for(head = 0; head < len -1; head++)
		for(seek = head + 1; seek < len; seek++)
			if(wordlen(strings[head])>wordlen(strings[seek]))
			{
				temp = strings[head];
				strings[head] = strings[seek];
				strings[seek] = temp;
			}
}

int wordlen(char *s)
{
	int len = 0;
	char *t = s;
	while(isspace(*t))
		t++;
	while(isalpha(*t)){
		t++;
		len++;
	}
	return len;
}
