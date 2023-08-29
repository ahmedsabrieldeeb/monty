#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"

/* global variables */
FILE *file;


/**
 * main - starting point
 * @argc: number of arguments passed while executing
 * @argv: array of arguments stings passed while executing
 *
 * Return: 0 on success, EXIT_FAILURE on fails
*/
int main(int argc, char **argv)
{
	/* local variables */
	char buffer[BUFFER_SIZE];
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	checkArguments(argc, argv);		/* checking arguments validity */

	file = checkFile(argv[1]);		/* opening the file validity */

	/* reading the file line by line */
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		line_number++;
		/* process the line */
		if (!extractInstruction(buffer, line_number, &stack))
		{
			fclose(file);
			free_stack(&stack);
			exit(EXIT_FAILURE);
		}
	}
	fclose(file);
	free_stack(&stack);
	return (0);
}

/**
 * extractInstruction - extracting the instruction from the line
 * @line: line to be parsed
 * @line_num: line number in the file
 * @ps: a double pointer to the stack itself
 *
 * Return: 0 on success, EXIT_FAILURE on fails
*/
int extractInstruction(char *line, unsigned int line_num, stack_t **ps)
{
	instruction_t opcodes[] = {
		{"nop", nop}, {"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add}};

	char *word;
	size_t i;

	word = strtok(line, " \t\n");
	if (word != NULL)
	{
		for (i = 0; i < sizeof(opcodes) / sizeof(opcodes[0]); i++)
		{
			if (strcmp(word, opcodes[i].opcode) == 0)
			{
				opcodes[i].f(ps, line_num);
				return (1);
			}
		}
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, word);
		return (0);		/* invalid instruction */
	}
	return (1);		/* empty line */
}
