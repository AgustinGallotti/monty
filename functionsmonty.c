#define _GNU_SOURCE
#include "monty.h"
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
	stack_t *ptr;

	ptr	= malloc(sizeof(stack_t));
	if (ptr == NULL)
	{
		printf("Error: malloc failed\n");
		exitwrap(EXIT_FAILURE, NULL, *top);
	}
	ptr->n = val;
	if (*top == NULL)
	{
		ptr->prev = NULL;
		ptr->next = NULL;
		*top = ptr;
		*bot = ptr;
	}
	else if (mode == STACKMODE)
	{
		ptr->next = NULL;
		ptr->prev = *top;
		(*top)->next = ptr;
		*top = ptr;
	}
	else if (mode == QUEUEMODE)
	{
		ptr->prev = NULL;
		ptr->next = *bot;
		(*bot)->prev = ptr;
		*bot = ptr;
	}
}

/**
* pall_ print all values
*
* @top: top of stack
*/
void pall(stack_t **top)
{
	stack_t *ptr = *top;

	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->prev;
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
		exitwrap(EXIT_FAILURE, "can't pint, stack empty", *top);
	printf("%d\n", (*top)->n);
}

/**
* pop - funciton to top element
*
* @top: top of stack
*/
void pop(stack_t **top)
{
	stack_t *ptr = *top;

	if (ptr == NULL)
		exitwrap(EXIT_FAILURE, "can't pop an empty stack", *top);
	if (ptr->prev == NULL)
	{
		free(*top);
		*top = NULL;
	}
	else
	{
		ptr = ptr->prev;
		ptr->next = NULL;
		free(*top);
		*top = ptr;
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
		exitwrap(EXIT_FAILURE, "can't swap, stack too short", *top);
	pointer = pointer->prev;
	(*top)->prev = pointer->prev;
	pointer->next = (*top)->next;
	pointer->prev = *top;
	(*top)->next = pointer;
	*top = pointer;
	if ((*bot)->prev != NULL)
		*bot = (*bot)->prev;
}
