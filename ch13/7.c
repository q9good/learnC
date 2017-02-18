#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 50

int main(int argc, char *argv[])
{
	char line1[LEN], line2[LEN];
	FILE *fp1, *fp2;
	int half;

	if(argc < 3){
		fprintf(stderr, "Usage: %s filename1 filename2\n", argv[0]);
		exit(0);
	}

	if((fp1 = fopen(argv[1],"r")) == NULL){
		fprintf(stderr, "can't open file %s\n", argv[1]);
		exit(1);
	}

	if((fp2 = fopen(argv[2],"r")) == NULL){
		fprintf(stderr, "can't open file %s\n", argv[2]);
		exit(2);
	}

	while(1){
		if(fgets(line1, LEN, fp1) != NULL)
			fputs(line1,stdout);
		else
		{
			if(half == 1)
				break;
			else
				half = 1;
		}
		if(fgets(line2, LEN, fp2) != NULL)
			fputs(line2,stdout);
		else
		{
			if(half == 1)
				break;
			else
				half = 1;
		}
	}

	if(fclose(fp1) != 0)
		fputs("Error in close file",stdout);
	if(fclose(fp2) != 0)
		fputs("Error in close file",stdout);

	return 0;
}
