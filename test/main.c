#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"

char *extractInstruction(char *line);

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

	/* checking arguments validity */
	checkArguments(argc, argv);

	/* opening the file validity */
	file = checkFile(argv[1]);

	/* reading he file line by line */
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		/* process the line */
		extractInstruction(buffer);
	}


	return (0);
}

char *extractInstruction(char *line)
{
	char *word;

	word = strtok(line, " \t\n");
	while (word != NULL)
	{
		printf("Inside %s\n", word);
		word = strtok(NULL, " \t\n");
	}

	return NULL;
}
