#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * push_function - push an integer to the stack
 * @stack: a double pointer to the stack itself
 * @line_number: line number in the file
 *
 * Return: void
*/

void push_function(stack_t **stack, unsigned int line_number)
{
	int value;
	char *argument;
	stack_t *pn;

	argument = strtok(NULL, " \t\n");
	if (argument == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (!is_number(argument))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(argument);

	pn = (stack_t *)malloc(sizeof(stack_t));
	if (pn == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	pn->n = value;
	pn->prev = *stack;
	pn->next = NULL;
	*stack = pn;

}
