#include "shell.h"

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
 * Free memory allocated for an array of arguments.
 * @args: Array of command and arguments.
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
