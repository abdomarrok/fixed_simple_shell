#include "shell.h"

/**
 * execute_external_command - Execute an external command.
 * @args: Command to be executed.
 *
 * This function executes the specified external command.
 *
 * Return: The exit status of the executed command.
 */
int execute_external_command(char **args)
{
	pid_t child = fork();

	if (child == -1)
	{
		perror("problem");
		return (-1);
	}
	else if (child == 0)
	{
		execve(args[0], args, environ);
		perror("execve");
		_exit(EXIT_FAILURE);
	}
	else
	{
		int status;
		int exit_status;

		waitpid(child, &status, 0);
		if ((status & 0xff) == 0)
			exit_status = (status >> 8) & 0xff;
		else
			exit_status = -1;
		return (exit_status);
	}
}
