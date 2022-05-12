#include "monty.h"

/**
 * free_stack - frees the stack
 * @stack: pointer to the stack
 * Return: Nothing
 */
void free_stack(stack_t **stack)
{
	stack_t *head;
	stack_t *tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
