#include "shell.h"

/**
 * get_input - This function prints the prompt and gets the user's input (Command and Arguments).
 * Return: An array containing the command as the first item (args[0]), and the arguments as separate items.
 */
char **get_input(void)
{
char *input = NULL;
size_t len = 0;
ssize_t response;
char **args = NULL;
    

write(STDOUT_FILENO, "($)  ", 2);

response = read_user_input(&input, &len);

if (response == (ssize_t)-1)
{
free(input);
exit(EXIT_FAILURE);
}
else if (response == 0)
{
printf("EOF detected. Exiting the shell.\n");
free(input);
exit(EXIT_SUCCESS);
}

args = parse_input(input);

free(input);

return args;
}