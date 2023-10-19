#include "shell.h"

/**
 * run_command - Execute a command represented by the args array.
 * @args: An array of strings containing the command and its arguments.
 *
 * This function checks if the specified command is executable and, if so,
 * forks a new process to execute the command using execve.
 * After execution, it cleans up allocated resources.
 */
void run_command(char **args)
{
	if (args[0] != NULL && access(args[0], X_OK) == 0)
	{
		pid_t child = fork();
		int i;

		if (child == -1)
		{
			perror("problem");
			exit(EXIT_FAILURE);
		}
		else if (child == 0)
		{
			execve(args[0], args, environ);
			perror("execve");
			for (i = 0; args[i] != NULL; i++)
				free(args[i]);
			free(args);
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
			for (i = 0; args[i] != NULL; i++)
				free(args[i]);
			free(args);
		}
	}
	else
	{
		int i;

		for (i = 0; args[i] != NULL; i++)
		{
			free(args[i]);
		}
		free(args);
	}
}
