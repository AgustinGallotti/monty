#define _GNU_SOURCE
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

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
	if (*top == NULL)
	{
		pointer->prev = NULL;
		pointer->next = NULL;
		*top = pointer;
		*bot = pointer;
	}
	else if (mode == STACKMODE)
	{
		pointer->next = NULL;
		pointer->prev = *top;
		(*top)-next = pointer;
		*top = pointer;
	}
	else if (mode == QUEUEMODE)
	{
		pointer->prev = NULL;
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

/**
*
*
*
*/
void pop(stack_t **top)
{
	stack_t *pointer = *top;

	if (pointer == NULL)
		exit(EXIT_FAILURE, "can't pop an empty stack", *top);
	if (pointer->prev == NULL)
	{
		free(*top);
		*top = NULL;
	}
	else
	{
		pointer = pointer->prev;
		pointer->next = NULL;
		free(*top);
		*top = pointer;
	}
}

/**
* swap - swap to values on stack
*
* @top: top of the stack
* @bot: bottom of stack
*/
void swap(stack_t **top, stack_t **bot)
{
	stack_t *pointer = *top;

	if (pointer == NULL || pointer->prev == NULL)
		exit(EXIT_FAILURE, "can't swap, stack too short", *top);
	pointer = pointer->prev;
	(*top)->prev = pointer->prev;
	pointer->next = (*top)->next;
	pointer->prev = *top;
	(*top)->next = pointer;
	*top = pointer;
	if ((*bot)->prev != NULL)
		*bot = (*bot)->prev;
}
