#include "shell.h"

/**
 * main - Entry point of the shell program.
 *
 * Description: This function serves as the entry point for the shell program. It
 * runs an infinite loop to continuously prompt for and execute user commands.
 *
 * Return: Always returns 0.
 */

int main(void)
{
while (1)
{
char **args = get_input();

if (args == NULL)
{
write(STDOUT_FILENO, "Error occurred while getting input.\n", 36);
continue;
}

if (args[0] == NULL)
{
free_arguments(args);
continue;
}

execute_user_command(args);
free_arguments(args);
}
}

/**
 * free_arguments - Free memory allocated for an array of arguments.
 * @args: Array of command and arguments.
 *
 * Description: This function releases the memory allocated for an array of
 * command and arguments. It should be used to clean up resources after
 * executing commands.
 */
void free_arguments(char **args)
{
int i;
for (i = 0; args[i] != NULL; i++)
{
free(args[i]);
}
free(args);
}
