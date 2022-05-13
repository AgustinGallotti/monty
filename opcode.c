#include "monty.h"

/**
 * op_func - This function selects the correct func to
 * perform the operation
 * @s: The operator passed as argument to program
 * @stack: The pointer to the stack
 * @line_number: The line number in the file
 * Return: A pointer to the function that corresponds to the operator
 */

stack_t *(*op_func(char *s, stack_t **stack, unsigned int line_number))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"add", add},
		{"swap", swap},
		{NULL, NULL}
	};
	char *opcode;
	int i = 0;

	while (i < 8)
	{
		opcode = (ops[i]).opcode;
		/* if the opcode is in the list */
		if (strcmp(s, opcode) == 0)
		{
			/* return that value */
			return (*(ops[i]).f);
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, s);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
