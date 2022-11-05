#include "main.h"

/**
 * execute - Executes shell commands
 * @args: Arguments to be executed
 */

void execute(char **args)
{
	/* Execute the command using execve or execvp function */
	if (strcmp(args[0], "cd") == 0)
	{
		if (chdir(args[1]) == -1)
			perror("Error");
	}
	else if (strcmp(args[0], "exit") == 0)
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
