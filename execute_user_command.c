#include "shell.h"

/**
 * Execute a user command based on the first argument.
 * @args: Array of command and arguments.
 *
 * This function executes a user command based on the first argument.
 */
void execute_user_command(char **args)
{
if (_strchr(args[0], '/') != NULL)
{
run_command(args);
}
else
{
if (_strcmp(args[0], "exit") == 0)
{
exit_shell(args);
}
else if (_strcmp(args[0], "env") == 0)
{
env_builtin();
}
else if (_strcmp(args[0], "setenv") == 0)
{
updateEnvironmentVariable(args);
}
else if (_strcmp(args[0], "unsetenv") == 0)
{
removeEnvironmentVariable(args);
}
else if (_strcmp(args[0], "cd") == 0)
{
cd_handler(args);
}
else
{
execute_command(args);
}
}
}
