#include "shell.h"

/**
 * exit_shell - Handle the exit command for the shell.
 * @args: Array of arguments, where args[1] is the exit status (optional).
 *
 * Description: This function handles the exit command for the shell. It can optionally
 * take an exit status as an argument.
 */
void exit_shell(char **args)
{
	int i;

	if (args[1] != NULL)
	{
		int exit_status = strTOint(args[1]);

		for (i = 0; args[i] != NULL; i++)
		{
			free(args[i]);
		}
		free(args);
		exit(exit_status);
	}

	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}
	free(args);
	exit(0);
}
