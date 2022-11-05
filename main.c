#include "main.h"

/**
 * main - reads, parses and executes shell commands
 *
 * Return: 0 on success
 */

int main()
{
	/* main function with while loop of our shell */
	while (true)
	{
		printf(":)$ ");

		char *input = read_line();
		char **parsed = parse(input);

		execute(parsed);

		free(input);
		free(parsed);
	}

	return (0);
}
