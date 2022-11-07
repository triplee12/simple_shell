#include "main.h"

/**
 * execute - Executes shell commands
 * @args: Arguments to be executed
 */

void execute(char **args)
{
	/* Execute the command using execve or execvp function */
	if (_strcmp(args[0], "cd") == 0)
	{
		if (chdir(args[1]) == -1)
			perror("Error");
	}
	else if (_strcmp(args[0], "env") == 0)
	{
		char *dup = getenv("PATH");
		char *s = dup;
		char *p = NULL;
		do {
			p = strtok(s, ":");
			if (p != NULL)
				p[0] = 0;
			printf("%s\n", s);
			s = p + 1;
		} while (p != NULL);
	}
	else if (_strcmp(args[0], "exit") == 0)
		exit(0);
	else
	{
		if (fork() == 0)/* checks any current running process */
		{
			int status_code = execve(args[0], args, NULL); /* Change execve to execvp(args[0], args) envp|NULL excluded */

			if (status_code == -1)/* checks valid command */
				perror("Error: Execution error.");
		}
		else
			wait(NULL); /* wait for child process to finish, to avoid zombi state | orphan state */
	}
}
