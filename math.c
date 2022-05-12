#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
* add - add top two stack elements
*
* @top: top of stack
*/
void add(stack_t **top)
{
	stack_t *pointer = *top;
	long num;

	if (pointer == NULL || pointer->prev == NULL)
		exit(EXIT_FAILURE, "can't add, stack to short", *top);
	else
	{
		num = pointer->n;
		pointer = pointer->prev;
		pointer->next = NULL;
		free(*top);
		*top = pointer;
		pointer->n += num;
	}
}
