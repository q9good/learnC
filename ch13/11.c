#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 60

int main(int argc, char *argv[])
{
	char buf[LEN];
	char *pos;
	FILE *fp;
	if(argc != 3)
	{
		fprintf(stdout, "Usage: %s string filename.\n", argv[0]);
		exit(0);
	}

	if((fp=fopen(argv[2], "r")) == NULL)
	{
		fprintf(stderr, "can't open file %s.\n", argv[2]);
		exit(1);
	}

	while(fgets(buf, LEN-1,fp) != NULL)
			if((pos=strstr(buf, argv[1])) != NULL)
				puts(pos);
	
	return 0;
}
