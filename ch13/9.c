#include <stdio.h>
#include <stdlib.h>

#define MAX 40

int main(void)
{
	 FILE *fp;
	 char words[MAX];
	 int count = 0;
	 int last;
	 if((fp=fopen("words","a+")) == NULL)
	 {
	 	fprintf(stdout, "can't open \"words\" file.\n");
		exit(1);
	 }
	
	fseek(fp, 0L, SEEK_END);
	if((last=ftell(fp) == 0)){
		count = 1;
		printf("%d\n", last);
	}
	else
	{
		printf("%d\n", last);
		rewind(fp);
		while(fgets(words, MAX, fp) != NULL)
			count++;
		count++;
	}
	puts("Enter words to add to fhe file; press the Enter.");
	puts("key at the beginning of a line to terminate.");
	while( fscanf(stdin,"%40s", words) == 1
									&& words[0] != EOF)
	 fprintf(fp, "%d: %s\n", count++, words);
	puts("File contents:");
	rewind(fp);
	while(fgets(words, MAX, fp) != NULL && words[0] != EOF)
		fputs(words, stdout);
	if(fclose(fp) != 0)
		fprintf(stderr, "Error closing file\n");
	return 0;
}
