#include "shell.h"

/**
 * handle_child_process - Function to handle child processes and execute cmd
 * @path: The path to the command to execute
 * @argument: An array of arguments for the command
 * @buffer: The input buffer
 * @env: The array of environment variables
 */
void handle_child_process(char *path, char **argument, char *buffer,
char **env)
{
pid_t child_id;
int status;

	child_id = fork();

	if (child_id < 0)
	{
		perror("fork error");
		if (buffer != NULL)
			free(buffer);
		exit(0);
	}
	else if (child_id == 0)
	{
	char *token = strtok(path, ":");

		while (token != NULL)
        {
        char executable_path[1024]; 
            snprintf(executable_path, sizeof(executable_path), "%s/%s", token, path);

            if (access(executable_path, X_OK) == 0)
            {
                /*Execute the command if found*/
                execve(executable_path, argument, env);
            }

            token = strtok(NULL, ":");
        }

        /* If the command is not found, print an error message*/
        perror("command not found");
        exit(1);
	}
	else
	{
		wait(&status);
	}
}
