#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"


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
	FILE * file __attribute__((unused));
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
			printf("closed\n");
			exit(EXIT_FAILURE);
		}
	}

	return (0);
}

/**
 * extractInstruction - extracting the instruction from the line
 * @line: line to be parsed
 * @line_num: line number in the file
 *
 * Return: 0 on success, EXIT_FAILURE on fails
*/
int extractInstruction(char *line, unsigned int line_num, stack_t **ps)
{
	/* list */
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall}};

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
		exit(EXIT_FAILURE);
	}

	return (0);
}
