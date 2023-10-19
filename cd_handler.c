#include "shell.h"

/**
 * Handle the "cd" (change directory) command.
 * @args: Array of arguments, where args[1] is the target directory.
 * Return: 0 on success, -1 on failure.
 */
int cd_handler(char **args)
{
char *new_directory = args[1];
char *home_directory = getenv("HOME");
char current_directory[4096];

if (new_directory == NULL || _strcmp(new_directory, "~") == 0)
{
new_directory = home_directory;
}
else if (_strcmp(new_directory, "-") == 0)
{
return handle_previous_directory();
}

if (get_current_directory(current_directory) == -1)
return -1;

if (change_directory(new_directory) == -1)
return -1;

if (update_directory_env_variables(current_directory, new_directory) == -1)
return -1;
    return 0;
}
