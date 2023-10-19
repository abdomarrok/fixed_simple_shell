#include "shell.h"

/**
 * Handle changing to the previous directory.
 * Return: 0 on success, -1 on failure.
 */
int handle_previous_directory(void)
{
char *old_directory = getenv("OLDPWD");

if (old_directory != NULL)
{
if (change_directory(old_directory) == -1)
return -1;
}
else
{
write(STDERR_FILENO, "OLDPWD environment variable not set\n", 37);
return -1;
}

return 0;
}

/**
 * Get the current working directory.
 * @current_directory: Buffer to store the current directory path.
 * Return: 0 on success, -1 on failure.
 */
int get_current_directory(char *current_directory)
{
if (getcwd(current_directory, sizeof(current_directory)) == NULL)
{
perror("getcwd");
return -1;
}
return 0;
}


