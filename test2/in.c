#include "shell.h"

/**
 * Read user input from the standard input.
 * @input: Pointer to the input buffer.
 * @len: Pointer to the buffer length.
 * Return: The number of characters read or -1 on failure.
 */
ssize_t read_user_input(char **input, size_t *len)
{
    return _getline(input, len, stdin);
}

/**
 * Parse the user input into command and arguments.
 * @input: The input string to be parsed.
 * Return: An array containing the command and arguments.
 */
char **parse_input(char *input)
{
    char *token = NULL;
    char **args = NULL;
    size_t arg_count = 0;

    token = _strtok(input, " \n");
    while (token != NULL)
    {
        args = add_argument(args, token, &arg_count);
        token = _strtok(NULL, " \n");
    }

    return args;
}


