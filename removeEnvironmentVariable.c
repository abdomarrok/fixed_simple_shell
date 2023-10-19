#include "shell.h"

/**
 * Remove an environment variable.
 * @args: An array containing the command and arguments.
 */
void removeEnvironmentVariable(char **args)
{
    if (args[1] == NULL)
    {
        char errorMsg[] = "Usage: removeEnvVar VARIABLE\n";
        write(STDERR_FILENO, errorMsg, 27);
        return;
    }

    if (args[2] != NULL)
    {
        char errorMsg[] = "removeEnvVar: Too many arguments\n";
        write(STDERR_FILENO, errorMsg, 22);
        return;
    }

    if (unsetenv(args[1]) == -1)
    {
        char errorMsg[] = "removeEnvVar: Error while unsetting environment variable\n";
        write(STDERR_FILENO, errorMsg, 53);
    }
}