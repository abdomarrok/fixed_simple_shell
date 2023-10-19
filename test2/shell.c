#include "shell.h"


int main(void)
{
	while (1)
	{
		char **args = get_input();
		int i;

		if (args == NULL)
		{
			write(STDOUT_FILENO, "Error occurred while getting input.\n", 36);
			continue;
		}

		if (args[0] == NULL)
		{
			for (i = 0; args[i] != NULL; i++)
				free(args[i]);
			free(args);
			continue;
		}

		if (_strchr(args[0], '/') != NULL)
		{
			run_command(args);
		}
		else
		{
			if (_strcmp(args[0], "exit") == 0)
			{
				exit_shell(args);
			}
			else if (_strcmp(args[0], "env") == 0)
			{
				/* Call the env_builtin function */
				env_builtin();
			}
			else if (_strcmp(args[0], "setenv") == 0)
			{
				 updateEnvironmentVariable(args);
			}
			else if (_strcmp(args[0], "unsetenv") == 0)
			{
				removeEnvironmentVariable(args);
			}
			else if (_strcmp(args[0], "cd") == 0)
			{
				cd_handler(args);
			}
			else
			{
				execute_command(args);
			}

			for (i = 0; args[i] != NULL; i++)
			{
				free(args[i]);
			}
			free(args);
		}
	}
}
