#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TSIZE 45
struct film{
	char title[TSIZE];
	int rating;
	struct film *next;
	struct film *prev;
};

int main(void)
{
	struct film *head = NULL, *tail = NULL;
	struct film *former, *current;
	char input[TSIZE];

	puts("Enter first moive tile:");
	while(gets(input) != NULL && input[0] != '\0')
	{
		current =(struct film *)malloc(sizeof(struct film));
		if(head == NULL)
			head = current;
		else
		{
			current->prev = former;
			former->next = current;
		}
		current->next = NULL;
		strcpy(current->title, input);
		puts("Enter your rating <0-10>:");
		scanf("%d", &current->rating);
		while(getchar() != '\n')
			continue;
		puts("Enter next movie tile(empty line to stop):");
		former = current;
		tail = current;
	}
	
	//positive sequence
	if(head == NULL)
		printf("No data entered");
	else 
		printf("Here is the moive list in positive sequence:\n");
	current = head;
	while(current != NULL)
	{
		printf("Moive: %s Rating %d.\n", current->title, current->rating);
		current = current->next;
	}
	//negative sequence
	if(tail == NULL)
		printf("No data entered");
	else
		printf("Here is the movie list in negative sequence:\n");
	current = tail;
	while(current != NULL)
	{
		printf("Moive: %s Rating %d.\n", current->title, current->rating);
		current = current->prev;
	}

	current =head;
	while(current != NULL)
	{
		free(current);
		current = current->next;
	}
	printf("Bye!\n");
}
