#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include "monty.h"

/**
 * checkArguments - check if argument is valid
 * @num_args: number of arguments passed while executing
 * @list_args: array of arguments stings passed while executing
 *
 * Return: void
*/
void checkArguments(int num_args, char **list_args)
{
	char *file_format;
	int i = 0;

	/* checking number of arguments */
	if (num_args != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* checking format of the file */
	file_format = list_args[1];
	while (*(file_format + i) != '\0')
	{
		if (*(file_format + i) == '.' && *(file_format + i + 1) == 'm' &&
			*(file_format + i + 2) == '\0')
		{
			return;
		}
		i++;
	}

	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * checkFile - check if file is valid
 * @file: file name to be checked
 *
 * Return: file descriptor on success, if not, throws an error
*/
int checkFile(char *file)
{
	int fd = open(file, O_RDONLY);

	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	return (fd);
}
