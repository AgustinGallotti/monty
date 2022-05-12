#define _GNU_SOURCE
#include "main.h"
#include <stdio.h>
#include <string.h>

#define MONTY 14

static typest stat;

/**
* main - function main
* @argc: number of agguments
* @argv: argument array
* Return: succes or error
*/
int main(int argc, char *argv[])
{
	optype *opcode;

	if (argc != 2)
	{
		printf("USAGE: monty file\n"); /*if not exist the format monty*/
		return (EXIT_FAILURE);
	}
	stat.script = fopen(argv[1], "r"); /*script pased, if the first is not a push*/
	if (stat.script == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	opcode = initop();
	stat.line = 1;
	parses(opcode); /*tomaría los argumentos pasados*/
	return (0);
}
/**
* exitmon - free and exit program
* @exitcod: exit code
* @exitstr: exit and error
* @topstack: free the stack
*/
void exitmonty(int exitcod, char *exitstr, stack_t *topstack)
{
	stack_t *pointer = topstack;

	if (exitstr != NULL)
		printf("L%lu: %s\n", stat.line, exitstr);
	while (top != NULL)
	{
		pointer = topstack->prev;
		free(topstack);
		topstack = pointer;
	}
	free(stat.buffer);
	fclose(stat.script);
	exit(exitcod);
}
