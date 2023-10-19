#include "shell.h"

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
