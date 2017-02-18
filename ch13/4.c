#include <stdio.h>

int main(int argc, char *argv[])
{
	int i;
	int ch;
	if(argc < 2){
		printf("Usage: %s filename1 filename2 ...\n", argv[0]);
		exit(0);
	}

	FILE *fp;
	for(i = 1; i < argc; i++){

		if((fp = fopen(argv[i],"r")) == NULL){
			printf("file %s not exist!\n", argv[i]);
			exit(1);
		}
		printf("file %s \n", argv[i]);
		ch = getc(fp);
		while(ch != EOF){
			putchar(ch);
			ch = getc(fp);
		}
		putchar('\n');
		fclose(fp);
	}

	return 0;
}
