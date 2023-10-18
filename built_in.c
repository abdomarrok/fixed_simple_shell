#include "shell.h"

/**
 * _built_in - Check for built-in shell commands.
 * @argument: An array of command arguments.
 * @env: The array of environment variables.
 *
 * Return: 1 if a built-in command is found, 0 otherwise.
 */
int _built_in(char **argument, char **env)
{
	int pipe_fd[2];
    pid_t child_id;
	char buffer[1024];
    ssize_t n;
    if (strcmp(argument[0], "exit") == 0)
    {
        _printstring("exit the shell\n");
        exit(0);
    }
    else if (strcmp(argument[0], "cd") == 0)
    {
        if (argument[1] == NULL)
        {
            chdir(getenv("HOME"));
        }
        else
        {
            chdir(argument[1]);
        }
        return (1);
    }
    else if (strcmp(argument[0], "env") == 0)
    {
        

        if (pipe(pipe_fd) == -1)
        {
            perror("pipe error");
            return (0);
        }

        child_id = fork();

        if (child_id < 0)
        {
            perror("fork error");
            return (0);
        }
        else if (child_id == 0)
        {
            close(pipe_fd[0]);
            dup2(pipe_fd[1], STDOUT_FILENO);
            close(pipe_fd[1]);
            _printstring(*env);
            exit(0);
        }
        else
        {
            close(pipe_fd[1]);
           
            while ((n = read(pipe_fd[0], buffer, sizeof(buffer))) > 0)
            {
                write(STDOUT_FILENO, buffer, n);
            }

            close(pipe_fd[0]); 
            wait(NULL);
        }
        return (1);
    }
    return (0);
}
