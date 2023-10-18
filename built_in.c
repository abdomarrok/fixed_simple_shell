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
(void)env;
if (strcmp(argument[0], "exit") == 0)
{
if (argument[1] != NULL)
{
int status = atoi(argument[1]);
_printstring("Exiting shell with status: ");
_printstring((char*)status);
_printstring("\n");
exit(status);
}
else
{
_printstring("exit the shell\n");
exit(0);
}
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
return (0);
}

