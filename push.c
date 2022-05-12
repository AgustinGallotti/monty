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
