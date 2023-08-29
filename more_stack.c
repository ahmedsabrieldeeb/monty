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

	second->prev->next = first;
	first->prev = second->prev;
	second->prev = first;
	first->next = second;
	second->next = NULL;
	*stack = second;
}
