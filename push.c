#include "monty.h"

/**
 * push - adds a node with the value token on the stack
 * @stack: ponter to the list stack
 * @line_number: unused variable
 * Return: address of the new node
 */
stack_t *push(stack_t **stack,
	      unsigned int line_number __attribute__((unused)))
{
	stack_t *new_node;

	/* Create new node */
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	/* Initialize the new node with the value of token */
	new_node->n = token;
	/* New node is placed at the beginning of the list */
	new_node->prev = NULL;
	new_node->next = *stack;

	/* If new node is not alone, update the following one */
	if (*stack != NULL)
		(*stack)->prev = new_node;

	/* head points to the new node */
	*stack = new_node;

	return (new_node);
}

/**
 * pall - print all
 * @stack: ponter to the list stack
 * @line_number: unused variable
 * Return: the address of the first node
 */
stack_t *pall(stack_t **stack,
	      unsigned int line_number __attribute__((unused)))
{
	stack_t *tmp;
	size_t node_c = 0;

	tmp = *stack;

	if (*stack == NULL)
	{
		return (NULL);
	}

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
		node_c++;
	}

	return (*stack);
}

/**
* sub - This function subtracts the top two nodes of the stack, stores it in
* the second node, and pops off the top node
* @stack: The stack list
* @line_number: The line number of the file
* Return: The edited stack
*/
stack_t *sub(stack_t **stack, unsigned int line_number)
{
	int diff = 0;
	stack_t *head = *stack;

	/* Check if stack is NULL */
	if (!head || !head->next)
	{
		/* Print error, free, and exit */
		fprintf(stderr, "L%d: can't sub, stack too short\n",
line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	/* Sum first two nodes, and store it in second node */
	diff = (head->next->n) - (head->n);
	head->next->n = diff;
	pop(stack, 0);

	return (*stack);
}

/**
* pstr - This function prints the string starting at the top of
* the stack
* @stack: The pointer to the stack
* @line_number: The current line number in the file
* Return: The pointer to the stack
*/
stack_t *pstr(stack_t **stack,
	      unsigned int line_number __attribute__((unused)))
{
	stack_t *head = *stack;

	if (!head)
		exit(EXIT_FAILURE);
	while (head)
	{
		if (head->n < 32 || head->n > 127)
			break;
		putchar(head->n);
		head = head->next;
	}
	putchar('\n');

	return (*stack);
}

/**
* pchar - prints the char at the top of the stack
* @stack: The stack list
* @line_num: The line number of the file
* Return: The head of the stack
*/
stack_t *pchar(stack_t **stack, unsigned int line_num)
{
	stack_t *head = *stack;

	/* Check if stack is NULL */
	if (!head)
	{
		/* Print error, free, and exit */
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	if (head->n < 0 || head->n > 127)
	{
		fprintf(stderr,
			"L%d: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}

	putchar(head->n);
	putchar('\n');

	return (*stack);
}
