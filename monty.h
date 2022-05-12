#ifndef MONTYH
#define MONTYH

#include <stdio.h>
#include <stdlib.h>

#define STACKMODE 0
#define QUEUEMODE 1

/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
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
* for stack, queues, LIFO, FIFO
*/

typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct stat
{
  char *buffer;
	unsigned long line;
	FILE* script;
} stat;

void pop(stack_t **top);
void swap(stack_t **top, stack_t **bot);
void push(stack_t **top, stack_t **bot, int val, int mode);

void pall(stack_t **top);
void pint(stack_t **top);

void add(stack_t **top);

void exit(int exitcod, char *exitstr, stack_t *top);

#endif
