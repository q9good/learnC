/* guess.c -- an inefficient and faulty number-guesser */
#include <stdio.h>
int main(void)
{
    int guess ;
    int lower, upper;
    lower = 0; 
    upper = 100; 
    printf("Pick an integer from 1 to 100. I will try to guess ");
    printf("input y if correct, a if bigger it, b smaller\n"); 
    printf("is your number %d?\n", (lower+upper)/2); 
    while ( (guess=getchar()) != 'y'){
	switch (guess){
		case 'a': upper = (lower+upper)/2;
			break;
		case 'b': lower = (lower+upper)/2;
			break;
		default:
			printf("please input correct one");
		}
	printf("is your number %d?\n", (lower+upper)/2); 
	}
	printf("ha, your number is %d\n",(lower+upper)/2); 
    return 0;
}
