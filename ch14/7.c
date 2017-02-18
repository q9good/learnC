#include <stdio.h>
#include <stdlib.h>

#define  MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10

struct book
{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int main(void)
{
	struct book library[MAXBKS];
	int count = 0;
	int index, filecount;
	FILE *pbooks;
	int size = sizeof(struct book);
	char ch;
	int del = 0;
	int i;

	if((pbooks = fopen("book.dat", "a+b")) == NULL)
	{
		fputs("Can't open book.dat file\n", stderr);
		exit(1);
	}

	rewind(pbooks);

	while(count < MAXBKS && fread(&library[count], size, 1, pbooks)==1)
	{
		if(count == 0)
			puts("Current contents of book.dat:");
			printf("%s by %s: %.2f\n", library[count].title,
				library[count].author,library[count].value);
		printf("r to reverse d to del e to edit:");
		ch = getchar();
		switch(ch)
		{
			case 'r': putchar('\n');
						while(getchar() != '\n')
						continue;
						break;
			case 'd': for( i = count; i < MAXBKS-1; i++)
						library[i] = library[i+1];
						del++;
					while(getchar() != '\n')
						continue;
						putchar('\n');
						break;
			case 'e': printf("please input new info.\n");
					getchar();
					puts("Now enter the title.");
					gets(library[count].title);
					puts("Now enter the author.");
					gets(library[count].author);
					puts("Now enter the value.");
					scanf("%f", &library[count++].value);
					while(getchar() != '\n')
						continue;
					putchar('\n');
					break;
		}

		count++;
	}

	filecount = count - del;
	if( filecount == MAXBKS)
	{
		fprintf(stderr, "The book.dat file is full\n");
		exit(2);
	}

	count = filecount;
	puts("Please add new book titles.");
	puts("Press [enter] at the start of a line to stop.");
	while(count < MAXBKS && gets(library[count].title) != NULL
						&& library[count].title[0] != '\0')
	{
		puts("Now enter the author.");
		gets(library[count].author);
		puts("Now enter the value.");
		scanf("%f", &library[count++].value);
		while(getchar() != '\n')
			continue;
		if(count < MAXBKS)
			puts("Enter the next title.");
	}

	if(count > 0)
	{
	puts("Here is the list of your books:");
	for(index = 0; index < count; index++)
		printf("%s by %s: %.2f\n", library[index].title,
				library[index].author, library[index].value);
	fwrite(&library[filecount], size, count - filecount, pbooks);
	}
	else 
		puts("No books? Too bad.\n");

	puts("Bye.\n");
	fclose(pbooks);

	return 0;
}

