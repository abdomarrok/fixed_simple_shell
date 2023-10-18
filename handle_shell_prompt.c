#include "shell.h"

/**
 * handle_shell_prompt - Function to handle the shell prompt
 */
void handle_shell_prompt(void)
{
	char *prmt = "($) ";
	char *buffer = NULL;
	size_t bsize;
	ssize_t num_of_chars;
	char *argument[11];

	if (isatty(0))
		_printstring(prmt);

	num_of_chars = getline(&buffer, &bsize, stdin);

	if (num_of_chars == -1)
	{
		free(buffer);
		exit(0);
	}

	handle_command(buffer, argument);
}
