#ifndef _MONTY_H_
#define _MONTY_H_

/* libraries */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/* Declaration of the global variables */
extern int token;

/* structures */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	stack_t *(*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Prototypes */

int main(int argc, char **argv);
stack_t *nop(stack_t **stack, unsigned int line_number);
stack_t *pop(stack_t **stack, unsigned int line_number);
stack_t *push(stack_t **stack, unsigned int line_number);
stack_t *pall(stack_t **stack, unsigned int line_number);
stack_t *add(stack_t **stack, unsigned int line_number);
void free_stack(stack_t **stack);
stack_t *(*op_func(char *s, stack_t **stack,
       unsigned int line_number))(stack_t **stack,
                      unsigned int line_number);
stack_t *pint(stack_t **stack, unsigned int line_number);
stack_t *swap(stack_t **stack, unsigned int line_number);

#endif /* _MONTY_H_ */
