#include "shell.h"

void handle_command(char *buffer, char **argument)
{
    int i = 0;
    int j = 0;
    char *delim = " \n";
    char *path;

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
