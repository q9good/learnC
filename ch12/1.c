/* global.c  -- uses an external variable */
#include <stdio.h>
void critic(int *p);
int main(void)
{
    int units = 0;         /* an external variable      */
    
    printf("How many pounds to a firkin of butter?\n");
    scanf("%d", &units);
    while ( units != 56)
        critic(&units);
    printf("You must have looked it up!\n");
    
    return 0;
}

void critic(int *p)
{
    /* optional redeclaration omitted */
    
    printf("No luck, my friend. Try again.\n");
    scanf("%d", p);
}
