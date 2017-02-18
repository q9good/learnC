#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40
#define SLEN 20

int main(void)
{
	FILE *source, *dest;
	char srcname[SLEN];
	char dstname[SLEN];
	int ch;
	int count = 0;

	printf("please input the name U want 2 compress:");
	gets(srcname);
	strcpy(dstname, srcname);
	strcat(dstname, "red");

	if((source = fopen(srcname, "r")) == NULL){
		fprintf(stderr, "couldn't open file %s\n", srcname);
		exit(0);
	}

	if((dest = fopen(dstname, "w")) == NULL){
		fputs("can't create file", stderr);
		exit(1);
	}

	while((ch=getc(source)) != EOF)
		if(count++ % 3 == 0)
			putc(ch, dest);

	if(fclose(source) != 0 || fclose(dest) != 0)
		fprintf(stdout, "Error in closing files\n");
	return 0;
}
