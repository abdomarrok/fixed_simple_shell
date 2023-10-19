#include "shell.h"

/**
 * handle_previous_directory - Change to the previous directory.
 *
 * changes the current working directory to the previous directory
 * as specified by the "OLDPWD" environment variable.
 *
 * Return: 0 on success, -1 on failure.
 */
int handle_previous_directory(void)
{
char *old_directory = getenv("OLDPWD");

if (old_directory != NULL)
{
if (change_directory(old_directory) == -1)
return (-1);
}
else
{
write(STDERR_FILENO, "OLDPWD environment variable not set\n", 37);
return (-1);
}

return (0);
}

/**
 * get_current_directory - Get the current working directory.
 * @current_directory: Buffer to store the current directory path.
 *
 * This function retrieves the current working directory and stores it in
 * the provided buffer.
 *
 * Return: 0 on success, -1 on failure.
 */
int get_current_directory(char *current_directory)
{
if (getcwd(current_directory, sizeof(current_directory)) == NULL)
{
perror("getcwd");
return (-1);
}
return (0);
}


