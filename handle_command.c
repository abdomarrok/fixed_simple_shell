#include "shell.h"

/**
 * handle_command - Function to handle command execution
 * @buffer: The input command buffer
 * @argument: An array of arguments for the command
 */
void handle_command(char *buffer, char **argument)
{
char *path;

	remove_newline(buffer);
	tokenize_arguments(buffer, argument);
	path = get_location(argument[0]);

	if (path == NULL)
	{
		if (_built_in(argument) != 0)
		{
			return;
		}
		else
		{
			perror("command not found\n");
			return;
		}
	}

	handle_child_process(path, argument);
}
