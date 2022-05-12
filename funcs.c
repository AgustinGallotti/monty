#include "monty.h"

/**
* add - This function adds the top two nodes of the stack, stores it in
* the second node, and pops off the top node
* @stack: The stack list
* @line_number: The line number of the file
* Return: The edited stack
*/
stack_t *add(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *head = *stack;

	/* Check if stack is NULL */
	if (!head || !head->next)
	{
		/* Print error, free, and exit */
		fprintf(stderr, "L%d: can't add, stack too short\n",
line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	/* Sum first two nodes, and store it in second node */
	sum = (head->n) + (head->next->n);
	head->next->n = sum;
	pop(stack, 0);

	return (*stack);
}

/**
* pint - This function prints the integer of the head
* @stack: Pointer to the stack
* @line_number: Line number of the file
* Return: Pointer to the stack
*/
stack_t *pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	head = *stack;

	if (head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", head->n);

	return (*stack);
}

/**
* pop - This function deletes the node at the top of the stack
* @stack: Pointer to the stack
* @line_number: Line number of the file
* Return: Pointer to the stack
*/
stack_t *pop(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	/* Head points to head of stack */
	stack_t *head = *stack;

	/* Check if stack is NULL */
	if (*stack == NULL)
	{
		/* Print error, free, and exit */
		fprintf(stderr, "L%d: can't pop an empty stack\n",
			line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	/* Stack now points to the next node */
	*stack = (*stack)->next;

	/* Free head node */
	free(head);

	/* If stack exists already, set it's prev pointer to NULL */
	if (*stack)
		(*stack)->prev = NULL;

	return (*stack);
}

/**
* swap - swaps the top two elements of the stack
* @stack: ponter to the list stack
* @line_number: unused variable
* Return: the address of the first node
*/
stack_t *swap(stack_t **stack,
	      unsigned int line_number __attribute__((unused)))
{
	stack_t *head;
	int tmp;

	head = *stack;

	if (head != NULL && head->next != NULL)
	{
		tmp = head->n;
		head->n = head->next->n;
		head->next->n = tmp;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
			line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	return (*stack);
}

/**
* nop - This function does nothing
* @stack: Pointer to the stack
* @line_number: Line number of file
* Return: Pointer to the stack
*/
stack_t *nop(stack_t **stack __attribute__ ((unused)),
	  unsigned int line_number __attribute__((unused)))
{
	return (0);
}
