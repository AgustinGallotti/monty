#include "monty.h"

#include <stdio.h>

/**
 * add - add top two stack elements. error if < 2 elements
 *
 * @top: top of stack
 */
void add(stack_t **top)
{
	stack_t *ptr = *top;
	long num;

	if (ptr == NULL || ptr->prev == NULL)
		exitwrap(EXIT_FAILURE, "can't add, stack too short", *top);
	else
	{
		num = ptr->n;
		ptr = ptr->prev;
		ptr->next = NULL;
		free(*top);
		*top = ptr;
		ptr->n += num;
	}
}
