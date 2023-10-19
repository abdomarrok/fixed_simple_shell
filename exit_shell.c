#include "shell.h"

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