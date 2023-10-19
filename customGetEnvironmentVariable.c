#include "shell.h"

/**
 * customGetEnvironmentVariable - Custom implementation of getenv.
 * @name: Name of the environment variable to retrieve.
 *
 * custom implementation of the getenv function to retrieve
 * the value of the specified environment variable from the 'environ' variable.
 *
 * Return: A pointer to the value of the environment variable,
 * or NULL if not found.
 */
char *customGetEnvironmentVariable(const char *name)
{
int i = 0;
int nameLength = _strlen(name);

if (name == NULL)
return (NULL);

for (; environ[i] != NULL; i++)
{
char *envVar = environ[i];

printf("Check environ[%d]: %s\n", i, environ[i]);

if (strncmp(envVar, name, nameLength) == 0)
{
char *value = strchr(envVar, '=');

if (value != NULL)
{
printf("Found a match for %s! Returning its value.\n", name);
return (environ[i] + _strlen(name) + 1);
}
}
}
printf("No match found for %s. Returning NULL.\n", name);
return (NULL);
}
