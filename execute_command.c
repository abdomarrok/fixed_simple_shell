#include "shell.h"

/**
 * execute_command - Execute commands if the command is detected.
 * @args: Command to be executed.
 *
 * This function executes the specified command if it's detected.
 *
 * Return: 0 on success, -1 on failure.
 */

int execute_command(char **args)
{
if (args[0] == NULL)
return (0);

if (access(args[0], X_OK) == 0)
{
return (execute_external_command(args));
}
else
{
char path[256], *binDirectory = "/bin/";
int i = 0, j = 0;

while (binDirectory[i] != '\0')
{
path[i] = binDirectory[i];
i++;
}

while (args[0][j] != '\0')
{
path[i] = args[0][j];
i++;
j++;
}

path[i] = '\0';

if (access(path, X_OK) == 0)
{
return (execute_external_command(args));
}
else
{
write(STDOUT_FILENO, "Command not found.\n", 19);
return (-1);
}
}
}
