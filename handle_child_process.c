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
        if (execve(path, argument, env) == -1)
        {
            perror("command does not exist\n");
            exit(1);
        }
    }
    else
    {
        wait(&status);
    }
}
