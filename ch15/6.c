#include <stdio.h>

#define ON 	1
#define OFF 0
#define LEFT 0
#define CENT 1
#define RIGT 2

struct format{
	unsigned int id		 	: 8;
	unsigned int size  		: 7;
	unsigned int alignment	: 2;
	unsigned int bold		: 1;
	unsigned int italic		: 1;
	unsigned int underline	: 1;
};

const char setting[]="ID SIZE ALIGNMENT B I U";
const char * options[]= {"change font", "change size",
						"chagne aligamen", "toggle bold",
						"toggle italic", "toggle underline",
						"quit"};

void showconfig(struct format);
void showmenu(void);
struct format chfont(struct format);
void chsize(struct format *);
void chalign(struct format *);
int getchoice(void);

int main(void)
{
	struct format parag = {1, 12};
	int ch;
	showconfig(parag);

	showmenu();
	while((ch = getchoice()) != 'q')
	{
		switch(ch)
		{
			case 'f':parag = chfont(parag);
					 break;
			case 's':chsize(&parag);
					 break;
			case 'a':chalign(&parag);
					 break;
			case 'b':parag.bold = ON;
					 break;
			case 'i':parag.italic = ON;
					 break;
			case 'u':parag.underline = ON;
					 break;
		}
		showconfig(parag);
		showmenu();
	}
	puts("Bye.");
	return 0;
}

void showconfig(struct format sf)
{
	printf("%s\n", setting);
	printf("%d %d", sf.id, sf.size);
	switch(sf.alignment){
		case LEFT: printf(" left"); break;
		case CENT: printf(" center"); break;
		case RIGT: printf(" right");break;
	}
	if(sf.bold)
		printf(" on");
	else 
		printf(" off");
	if(sf.italic)
		printf(" on");
	else 
		printf(" off");
	if(sf.underline)
		printf(" on");
	else 
		printf(" off");
	putchar('\n');
}

void showmenu(void)
{
	const char letters[] ="fsabiuq";
	int i;
	for(i = 0; i < 7; i++)
	{
		printf("%c)%s ", letters[i], options[i]);
		if((i + 1) % 3 == 0)
			putchar('\n');
	}
	putchar('\n');
}

struct format chfont(struct format sf)
{
	int font;
	printf("Enter font size (0-255):");
	scanf("%d", &font);
	while(getchar() != '\n')
		continue;
	sf.id = font & 0x0f;
	return sf;
}

void chsize(struct format * ps)
{
	int size;
	printf("Enter font size (0-127):");
	scanf("%d", &size);
	while(getchar() != '\n')
		continue;
	ps->size = size & 0x7f;
}

void chalign(struct format *ps)
{
	int ch;
	printf("Select alignment:\n");
	puts("l)left c)center r)right");
	ch = getchoice();
	switch(ch){
		case 'l': ps->alignment = LEFT; break;
		case 'c': ps->alignment = CENT; break;
		case 'r': ps->alignment = RIGT; break;
	}
}

int getchoice(void)
{
	char ch;
	ch = getchar();
	while(getchar() != '\n')
		continue;
	return ch;
}
