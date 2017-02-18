#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int countchar(char ch, void *src, int type);

int main(int argc, char *argv[])
{
	char ch;
	int count[argc-1];	
	int type = 1;		//get data from file
	int i;
	FILE *fp;

	if(argc < 2)
	{
		fprintf(stderr, "Usege: %s char filename\n", argv[0]);
		exit(0);
	}
	
	if(strlen(argv[1]) != 1)
	{
		fprintf(stderr, "Usege: %s char filename\n", argv[0]);
		exit(1);
	}
	
	ch = *argv[1];

	if( argc == 2){
		type = 0;
		count[0] = countchar(ch, stdin, type);
		printf("stdin has %d char %c\n", count[0], ch);
	}
	else
	{
		for( i = 2; i < argc; i++)
		{
			if((fp=fopen(argv[i],"r")) == NULL)
			{
				fprintf(stderr,"can't open file %s\n", argv[i]);
				continue;
			}
			else
			{
				count[i-1] = countchar(ch, fp, type);
				printf("file %s has %d char %c\n", argv[i],
								count[i-1], ch);
			}
			fclose(fp);
		}
		for(i = 1,count[0] = 0; i < argc -1; i++)
		{
			count[0] += count[i];
		}
	}
	return 0;
}
	
int countchar(char ch, void *src, int type)
{
	char g;
	int cnt = 0;
	FILE *fp;
	if(type == 0)
	{
		while((g=getchar()) != EOF){
			if(g == ch)
				cnt++;
		}
	}
	else
	{
		fp = (FILE*)src;
		while((g=getc(fp)) != EOF){
			if(g == ch)
				cnt++;
		}
	}
	return cnt;
}
