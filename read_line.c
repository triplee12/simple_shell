#include "main.h"

/**
 * read_line - Accepts input from standard input (stdin)
 *
 * Return: buffer read on success, otherwise -1
 */

char *read_line()
{
	/* Accept input from stdin with getline() function */

	char *buffer;
	size_t buffsize = 100;
	size_t line;

	buffer = (char*) malloc(buffsize * sizeof(char));

	if (buffer == NULL)
	{
		printf("Error: Couldn't allocate memory\n");
		exit(1);
	}

	line = getline(&buffer, &buffsize, stdin);

	return (buffer);
}
