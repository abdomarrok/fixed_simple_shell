#include "shell.h"

int main(int argc, char **env)
{
    char *prmt = "($) ", *buffer = NULL,*delim = " \n";
    (void)argc;
    char *argument[11],*path;
    size_t bsize;
    ssize_t num_of_chars;
    pid_t child_id;
    int status, i, j;

    while (1)
    {
        if (isatty(0))
            _printstring(prmt);

        num_of_chars = getline(&buffer, &bsize, stdin);

        if (num_of_chars == -1)
        {
            free(buffer);
            exit(0);
        }
        i = 0;
        while (buffer[i])
        {
            if (buffer[i] == '\n')
            {
                buffer[i] = 0;
            }
            i++;
        }

        j = 0;
        argument[j] = strtok(buffer, delim);

        while (argument[j])
        {

            argument[++j] = strtok(NULL, delim);
        }
        argument[j] = NULL;

        path = get_location(argument[0]);
        if (path == NULL)
        {
            if (_built_in(argument) != 0)
            {

                continue;
            }
            else
            {
                perror("command do not found \n ");
                continue;
            }
        }

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
                perror("command do not exist \n ");
            };
        }
        else
        {
            wait(&status);
        }
    }

    free(buffer);
    return (0);
}