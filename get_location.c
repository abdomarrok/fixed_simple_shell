#include "shell.h"

/**
 * place - Search for a command in directories listed in PATH.
 * @path: The PATH environment variable.
 * @argument: The command to find.
 *
 * Return: The full path to the command if found, otherwise NULL.
 */
char *place(char *path, char *argument)
{
	char *path2, *path_token, *file_path, *delim = ":";
    
	path2 = strdup(path);
	path_token = strtok(path2, delim);

	file_path = malloc(strlen(argument) + strlen(path_token) + 4);

	while (path_token != NULL)
	{
		strcpy(file_path, path_token);
		strcat(file_path, "/");
		strcat(file_path, argument);
		strcat(file_path, "\0");
		if (access(file_path, X_OK) == 0)
		{
			return (file_path);
		}
		path_token = strtok(NULL, delim);
	}
	free(file_path);
	free(path2);

	return (NULL);
}

/**
 * get_location - Get the full path to a command by searching PATH.
 * @command: The command to find.
 *
 * Return: The full path to the command if found, otherwise NULL.
 */
char *get_location(char *command)
{
	char *path;

	path = getenv("PATH");

	if (path)
	{
		path = place(path, command);
		return (path);
	}
	return (NULL);
}
