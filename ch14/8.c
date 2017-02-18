#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LEN 14
#define SEATS 12
#define EMPTY 0
#define TAKEN 1
#define CONTINUE 1
#define DONE 0

struct planestats{
	int seat_id;
	int status;
	char last[LEN];
	char first[LEN];
};

int getmenu(void);
int getlet(const char*);
int openings(const struct planestats[], int);
void show_empties(const struct planestats[], int);                
void list_assign(struct planestats *[], int);
void assign_seat(struct planestats[], int);
void delete_seat(struct planestats[], int);
void sort(struct planestats *[], int);
char *s_gets(char *st, int n);

int main(void)
{
	struct planestats plane_1[SEATS], *ps[SEATS];
	int choice;
	int i;
	FILE *fp;
	int size = sizeof(struct planestats);

	for(i = 0; i < SEATS; i++)
		ps[i] = &plane_1[i];
	if ((fp = fopen("air.dat", "rb")) == NULL)
		for(i = 0; i < SEATS; i++)
		{
			plane_1[i].status = EMPTY;
			plane_1[i].seat_id = i + 1;
		}
	else
	{
		fread(plane_1, size, SEATS, fp);
		fclose(fp);
	}
	while( (choice = getmenu() ) != 'f')
	{
		switch(choice)
		{
			case 'a': printf("Thare are %d empty seats.\n");
					  openings(plane_1, SEATS);
					  break;
			case 'b': show_empties(plane_1, SEATS);
					  break;
			case 'c': list_assign(ps, SEATS);
					  break;
			case 'd': assign_seat(plane_1, SEATS);
					  break;
			case 'e': delete_seat(plane_1, SEATS);
					  break;
			default: puts("Switch trouble");
					 break;
		}
	}
	if((fp = fopen("air.dat", "wb")) == NULL)
		puts("Can't save data to file.");
	else
	{
		fwrite(plane_1, size, SEATS, fp);
		fclose(fp);
	}
	puts("Bye from Colussus Airlines!");
	return 0;
}

#define CHOICES 6
int getmenu(void)
{
	const char *descript[CHOICES] = {
		"Show number of empty seat",
		"Show list of empty seats",
		"Show aplhabetical list of seats",
		"Assign a customer to a seat assignment",
		"Delete a seat assignment",
		"Quit"
	};
	const char labels[CHOICES + 1] = "abcdef";
	int i;

	puts("To choose a function, enter its letter laber");
	for(i = 0; i < CHOICES; i++)
		printf("%c) %s\n", labels[i], descript[i]);
	return getlet(labels);
}
int getlet(const char *s)
{
	char c;
	c= getchar();
	while(strchr(s, c) == NULL)
	{
		printf("Enter a character in the list %s\n", s);
		while( getchar() != '\n');
			continue;
		c = getchar();
	}
	while( getchar() != '\n')
		continue;

	return c;
}

int openings(const struct planestats pl[], int len)
{
	int i, count = 0;
	for(i = 0; i < len; i++)
		if(pl[i].status == EMPTY)
			count++;
	return count;
}

void show_empties(const struct planestats pl[], int len)
{
	int i;
	if(openings(pl, len) == SEATS)
	{
		puts("All seats are empty");
		return;
	}
	for(i = 0; i < len; i++)
		if(pl[i].status == EMPTY)
			printf("seat_id %d is empty\n", pl[i].seat_id);
}

void list_assign(struct planestats *ps[], int len)
{
	int i;
	if(openings(*ps, len) == 0)
	{
		puts("All seats are  assigned");
	}
	else
	{
		sort(ps, len);
		for(i = 0; i < len; i++){
			if(ps[i]->status == TAKEN)
				printf("%d seat has been assigned to %s %s\n",
					ps[i]->seat_id,
					ps[i]->last,
					ps[i]->first);
		}
	}
}

void sort(struct planestats *ps[], int len)
{
	struct planestats *temp;
	int i, j;
	for(i = 0; i < len; i++)
		for(j = i + 1; j < len; j++)
		{
			if(strcmp(ps[i]->last, ps[j]->last) > 0)
			{
				temp = ps[i];
				ps[i] = ps[j];
				ps[j] = temp;
			}
		}
}

void assign_seat(struct planestats pl[], int len)
{
	char input[LEN];
	int seat;
	int ok = 0;
	printf("please input which seat want to assign:");
	while(ok != 1)
	{
		scanf("%d", &seat);
		if(pl[seat-1].status == TAKEN || seat > SEATS || seat <1)
			printf("\nplease input another seat available:");
		else
			ok = 1;
			seat -= 1;
	}
	while( getchar != '\n')
		continue;
	puts("Enter the last name!");
	s_gets(pl[seat].last, LEN);
	puts("Enter the first name!");
	s_gets(pl[seat].first, LEN);
	pl[seat].status = TAKEN;
}

void delete_seat(struct planestats pl[], int len)
{
	int del;
	int ret = 0;
	printf("choose the seat want to del from list below:");
	list_assign(pl, len);
	while( ret != 1)
	{
		scanf("%d", &del);
		if(pl[del-1].status ==  TAKEN)
		{
			del -= 1;
			ret = 1;
		}
		else
		{
			puts("reEnter a assigned seat from list above");
		}
	}
	while(getchar() != '\n')
		continue;
	pl[del].status = EMPTY;
}

char *s_gets(char *st, int n)
{
	char *ret_val;
	char *find;
	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		find = strchr(st, '\n');
		if(find)
			*find = '\0';
		else
			while(getchar() != '\n')
				continue;
	}
	return ret_val;
}
	


































