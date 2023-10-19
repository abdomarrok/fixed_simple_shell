#include "shell.h"

/**
 * updateEnvironmentVariable - Modify or set an environment variable.
 * @args: An array containing the command and arguments.
 *
 * Description: This function allows you to modify or set an env variable.
 */
void updateEnvironmentVariable(char **args)
{
if (args[1] == NULL || args[2] == NULL)
{
char errorMsg[] = "Usage: updateEnvVar VARIABLE VALUE\n";
write(STDERR_FILENO, errorMsg, 29);
return;
}

if (args[3] != NULL)
{
char errorMsg[] = "updateEnvVar: Too many arguments\n";
write(STDERR_FILENO, errorMsg, 24);
return;
}

if (setenv(args[1], args[2], 1) == -1)
{
char errorMsg[] = "updateEnvVar: Error while setting environment variable\n";
write(STDERR_FILENO, errorMsg, 46);
}
}

