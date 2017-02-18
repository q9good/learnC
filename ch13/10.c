#include <stdio.h>
#include <stdlib.h>
#define LEN 40

int main(void)
{
	long pos;
	char ch;
	char path[LEN];
	FILE *fp;
	
	printf("please input the path of file:");
	fgets(path, LEN, stdin);
	//gets(path);
	printf("%s", path);	
	if((fp = fopen(path,"r")) == NULL)
	{
		fprintf(stdout,"can't open file %s\n", path);
		exit(0);
	}

	printf("please input the position want to output:");
	while(scanf("%ld", &pos) == 1){
		fseek(fp, pos, SEEK_SET);
		while((ch=getc(fp)) != '\n')
			putchar(ch);
		putchar('\n');
		printf("please input the position want to output:");
	}
	return 0;
}
