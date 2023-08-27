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

	/* checking arguments validity */
	checkArguments(argc, argv);

	/* opening the file validity */
	file = checkFile(argv[1]);

	/* parsing he file line by line */



	return (0);
}
