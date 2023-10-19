#include "shell.h"

/**
 * change_directory - Change the current working directory.
 * @path: The target directory path.
 *
 * This function changes the current working directory to the specified path.
 *
 * Return: 0 on success, -1 on failure.
 */
int change_directory(const char *path)
{
if (chdir(path) != 0)
{
perror("cd");
return (-1);
}
return (0);
}

/**
 * update_directory_env_variables - Update the PWD and OLDPWD .
 * @old_directory: The previous working directory path.
 * @new_directory: The new working directory path.
 *
 * This function updates the "PWD" and "OLDPWD" environment variables with the
 * paths of the previous and new working directories.
 *
 * Return: 0 on success, -1 on failure.
 */
int update_directory_env_variables(const char *old_directory,
const char *new_directory)
{
    if (setenv("OLDPWD", old_directory, 1) != 0 ||
setenv("PWD", new_directory, 1) != 0)
{
perror("setenv");
return (-1);
}
return (0);
}
