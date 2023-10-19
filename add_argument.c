#include "shell.h"

/**
 * Add a new argument to the list of arguments.
 * @args: The current array of arguments.
 * @arg: The new argument to be added.
 * @arg_count: Pointer to the argument count.
 * Return: The updated array of arguments.
 */
char **add_argument(char **args, char *arg, size_t *arg_count)
{
char **temp = realloc(args, (*arg_count + 1) * sizeof(char *));

if (temp == NULL)
{
perror("bash: realloc");
exit(EXIT_FAILURE);
}

args = temp;

args[*arg_count] = malloc(strlen(arg) + 1);
if (args[*arg_count] == NULL)
{
perror("bash: malloc:");
exit(EXIT_FAILURE);
}

_strcpy(args[*arg_count], arg);
(*arg_count)++;

return args;
}
