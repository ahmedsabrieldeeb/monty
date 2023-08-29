#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * swap - swapping the top two elements
 * @stack: a double pointer to the stack itself
 * @line_number: line number in the file
 *
 * Return: void
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if ((*stack) == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = (*stack)->prev;

	if (second->prev == NULL)
	{
		first->prev = NULL;
		first->next = second;
		second->prev = first;
		second->next = NULL;
		*stack = second;
	}
	else
	{
		second->prev->next = first;
		first->prev = second->prev;
		second->prev = first;
		first->next = second;
		second->next = NULL;
		*stack = second;
	}
}

/**
 * nod - do nothing
 * @stack: a double pointer to the stack itself
 * @line_number: line number in the file
 *
 * Return: void
*/
void nod(stack_t **stack __attribute__((unused)), unsigned int line_number __attribute__((unused)))
{
	return;
}
