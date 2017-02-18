#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void InitializeStack(Stack *ps)
{
	ps->top = 0;
}

bool FullStack(const Stack *ps)
{
	return ps->top == MAXSTACK;
}

bool EmptyStack(const Stack *ps)
{
	return ps->top == 0;
}

bool Push(Item item, Stack *ps)
{
	if(FullStack(ps))
		return false;
	else
	{
		ps->item[ps->top] = item;
		ps->top++;
		return true;
	}
}

bool Pop(Item *pitem, Stack *ps)
{
	if(EmptyStack(ps))
		return false;
	else
	{
		ps->top--;
		*pitem = ps->item[ps->top];
		return true;
	}
}
