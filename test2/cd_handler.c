#include "shell.h"

int cd_handler(char **args)
{
	char *new_directory = args[1], *home_directory = getenv("HOME"),
	current_directory[4096];

	if (new_directory == NULL || _strcmp(new_directory, "~") == 0)
	{
		new_directory = home_directory;
	}
	else if (_strcmp(new_directory, "-") == 0)
	{
		char *old_directory = getenv("OLDPWD");

		if (old_directory != NULL)
		{
			new_directory = old_directory;
		}
		else
		{
			write(STDERR_FILENO, "OLDPWD environment variable not set\n", 37);
			return (-1);
		}
	}

	if (getcwd(current_directory, sizeof(current_directory)) == NULL)
	{
		perror("getcwd");
		return (-1);
	}

	if (chdir(new_directory) != 0)
	{
		perror("cd");
		return (-1);
	}
	else
	{
		if (setenv("OLDPWD", current_directory, 1) != 0 || setenv("PWD", new_directory, 1) != 0)
		{
			perror("setenv");
			return (-1);
		}
	}
	return (0);
}