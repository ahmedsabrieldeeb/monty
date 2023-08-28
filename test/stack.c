#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * push - push an integer to the stack
 * @stack: a double pointer to the stack itself
 * @line_number: line number in the file
 *
 * Return: void
*/
void push(stack_t **stack, unsigned int line_number)
{
	int value;
	char *argument;
	stack_t *pn;

	argument = strtok(NULL, " \t\n");
	if (argument == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	if (!is_number(argument))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(stack);
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

/**
 * pall - printing all the elements of the stack
 * @stack: a double pointer to the stack itself
 * @line_number: line number in the file
 *
 * Return: void
*/
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *current = *stack;

	if (current == NULL)
		return;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}

/**
 * free_stack - freeing any memory allocated fro the stack
 * @ps: a double pointer to the stack itself
 *
 * Return: void
*/
void free_stack(stack_t **ps)
{
	stack_t *next;

	while (*ps != NULL)
	{
		next = (*ps)->prev;
		free(*ps);
		*ps = next;
	}
}
