#include <stdio.h>
#include <string.h>

#define 	ON 		1
#define 	OFF 	0
#define 	LEFT 	0
#define 	CENT 	1
#define 	RIGT 	2

#define 	ID_MASK 	0x00fff
#define 	SIZE_MASK 	0xff01f
#define		ALG_MASK	0xfffe7
#define		BOLD_MASK	0x04
#define		ITAL_MASK	0x02
#define		UND_MASK	0x01

#define		ID_SFT		12
#define		SIZE_SFT	5
#define		ALG_SFT		3
#define		BOLD_SFT	2
#define		ITAL_SFT	1

typedef unsigned long parag; 

const char setting[]="ID SIZE ALIGNMENT B I U";
const char * options[]= {"change font", "change size",
						"chagne aligamen", "toggle bold",
						"toggle italic", "toggle underline",
						"quit"};
const char letters[] ="fsabiuq";

void showmenu(void);
int getchoice(const char *);
void show_config(parag);
parag get_id(parag);
void get_size(parag *);
void get_align(parag *);

int main(void)
{
	int ch;
	parag pattern = 1<<ID_SFT | 12 << SIZE_SFT | LEFT << ALG_SFT;
	show_config(pattern);
	showmenu();
	while((ch = getchoice(letters)) != 'q')
	{
		switch(ch)
		{
			case 'f': pattern = get_id(pattern); break;
			case 's': get_size(&pattern);	break;
			case 'a': get_align(&pattern); break;
			case 'b': pattern ^= BOLD_MASK; break;
			case 'i': pattern ^= ITAL_MASK; break;
			case 'u': pattern ^= UND_MASK; break;
		}
		show_config(pattern);
		showmenu();
	}
	puts("Bye!");
	return 0;
}

void showmenu(void)
{
	int i;
	for(i = 0; i < 7; i++)
	{
		printf("%c)%s ", letters[i], options[i]);
		if((i + 1) % 3 == 0)
			putchar('\n');
	}
	putchar('\n');
}

int getchoice(const char *src)
{
	char ch;
	ch = getchar();
	while(strchr(src, ch) == NULL)
	{
		printf("please input char in %s\n", src);
		while(getchar() != '\n')
			continue;
		ch = getchar();
	}
	while(getchar() != '\n')
		continue;
	return ch;
}

void show_config(parag p)
{
	parag b, align;
	printf("%s\n", setting);
	printf("%d %d", (p&~ID_MASK)>>ID_SFT, (p&~SIZE_MASK)>>SIZE_SFT);
	align = (p&~ALG_MASK) >> ALG_SFT;
	switch(align)
	{
		case LEFT : printf(" left"); break;
		case CENT : printf(" center"); break;
		case RIGT : printf(" right"); break;
	}
	b = p & BOLD_MASK;
	if(b)
		printf(" on");
	else
		printf(" off");
	b = p & ITAL_MASK;
	if(b)
		printf(" on");
	else
		printf(" off");
	b = p & UND_MASK;
	if(b)
		printf(" on");
	else
		printf(" off");
	putchar('\n');
}

parag get_id(parag p)
{
	int id;
	printf("Enter font id (0~255):");
	scanf("%d", &id);
	while(getchar() != '\n')
		continue;
	p &= ID_MASK;
	p |= id << ID_SFT;
	return p;
}

void get_size(parag *p)
{
	int size;
	printf("Enter font size (0~127):");
	scanf("%d", &size);
	while(getchar() != '\n')
		continue;
	*p &= SIZE_MASK;
	*p |= size << SIZE_SFT;
}

void get_align(parag *p)
{
	int ch, alig;
	printf("Select alignment:\n");
	puts("l)left c)center r)right");
	ch = getchoice("lcr");
	switch(ch)
	{
		case 'l': alig = LEFT; break;
		case 'c': alig = CENT; break;
		case 'r': alig = RIGT; break;
	}
	*p &= ALG_MASK;
	*p |= alig << ALG_SFT;
}
