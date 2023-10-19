#include "shell.h"

/**
 * Change the current working directory to the specified path.
 * @path: The target directory path.
 * Return: 0 on success, -1 on failure.
 */
int change_directory(const char *path)
{
    if (chdir(path) != 0)
    {
        perror("cd");
        return -1;
    }

    return 0;
}

/**
 * Update the PWD and OLDPWD environment variables.
 * @old_directory: The previous working directory path.
 * @new_directory: The new working directory path.
 * Return: 0 on success, -1 on failure.
 */
int update_directory_env_variables(const char *old_directory, const char *new_directory)
{
    if (setenv("OLDPWD", old_directory, 1) != 0 || setenv("PWD", new_directory, 1) != 0)
    {
        perror("setenv");
        return -1;
    }

    return 0;
}
