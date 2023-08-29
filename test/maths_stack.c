#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * add - adding the top two and storing result at the second
 * and removing the top one
 * @stack: a double pointer to the stack itself
 * @line_number: line number in the file
 *
 * Return: void
*/
void add(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}

	(*stack)->prev->n = (*stack)->n + (*stack)->prev->n;
	pop(stack, line_number);
}
