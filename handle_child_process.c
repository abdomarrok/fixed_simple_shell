#include "shell.h"

/**
 * handle_child_process  Function handle child processes & execute commands
 * @path: The path to the command to execute
 * @argument: An array of arguments for the command
 */
void handle_child_process(char *path, char **argument)
{
	pid_t child_id;
	int status;

	child_id = fork();

	if (child_id < 0)
	{
		perror("fork error");
		free(buffer);
		exit(0);
	}
	else if (child_id == 0)
	{
		if (execve(path, argument, env) == -1)
		{
			perror("command does not exist\n");
		}
	}
	else
	{
		wait(&status);
	}
}
