#include "shell.h"

/**
 * tokenize_arguments - Function to tokenize command arguments
 * @buffer: The input command buffer
 * @argument: An array of arguments for the command
 */
void tokenize_arguments(char *buffer, char **argument)
{
    int j = 0;
    char *delim = " \n";
    argument[j] = strtok(buffer, delim);
    while (argument[j])
    {
        argument[++j] = strtok(NULL, delim);
    }
    argument[j] = NULL;
}
