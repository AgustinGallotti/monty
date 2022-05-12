#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>

/**
* push - push a vlaue in the stack
* @top: top of the stack
* @bot: bottom of stack
* @val: vlaue to push in the stack
* @mode: stack or queue mode, on top or buttom mode
*/
void push(stack_t **top, stack_t **bot, int val, int mode)
{
	stack_t *pointer;

	pointer	= malloc(sizeof(stack_t));
	if (pointer == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE, NULL, *top);
	}
	pointer->n = val;
	if (*top == NUL)
	{
		poniter->prev = NULL;
		pointer->next = NULL;
		*top = pointer;
		*bot = pointer;
	}
	else if (mode == STACKMODE)
	{
		poniter->next = NULL;
		poniter->prev = *top;
		(*top)-next = pointer;
		*top = pointer;
	}
	else if (mode == QUEUEMODE)
	{
		poniter->prev = NULL;
		pointer->next = *bot;
		(*bot)->prev = pointer;
		*bot = pointer;
	}
}

/**
* pall_ print all values
*
* @top: top of stack
*/
void pall(stack_t **top)
{
	stack_t *pointer = *top;

	while (pointer != NULL)
	{
		printf("%d\n", pointer->n);
		pointer = pointer->prev;
	}
}

/**
* pint - pint top of the stack
*
* @top: top of stack
*/
void pint(stack_t **top)
{
	if (top == NULL)
		exit(EXIT_FAILURE, "can´t pint, stack empty", *top);
	printf("d%\n", (*top)->n);
}
