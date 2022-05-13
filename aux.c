#include "monty.h"

/**
* rotl - The purpose of this function is to rotate the stack to the top
* @stack: The pointer to the top of the stack
* @line_number: The current line number in the file
* Return: The pointer to the stack
*/

stack_t *rotl(stack_t **stack,
	      unsigned int line_number __attribute__ ((unused)))
{
	stack_t *head = *stack;

	while (!head)
		head = head->next;

	/* stack now points to the second node */
	*stack = (*stack)->next;
	head->next = (*stack)->prev;
	(*stack)->prev = NULL;
	head->next->prev = head;
	head = head->next;
	head->next = NULL;

	return (*stack);
}

/**
* mod - This function computes the rest of the division of the
* second top element of the stack by the top element of the stack
* @stack: The pointer to the stack
* @line_number: The current line number in the file
* Return: The pointer to the stack
*/
stack_t *mod(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	int mod_int = 0;

	if (!head || !(head->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n",
line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if (head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	mod_int = (head->next->n) % (head->n);
	head->next->n = mod_int;
	pop(stack, 0);

	return (*stack);
}

/**
* mul_op - multiplies the second top element of the stack with the top one
* @stack: The stack list
* @line_num: The line number of the file
* Return: The edited stack
*/

stack_t *mul_op(stack_t **stack, unsigned int line_num)
{
	int result = 0;
	stack_t *head = *stack;

	/* Check if stack is NULL */
	if (!head || !head->next)
	{
		/* Print error, free, and exit */
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	result = (head->next->n) * (head->n);
	head->next->n = result;
	pop(stack, 0);

	return (*stack);
}
