#include "shell.h"

/**
 * is_delimiter - Check if a character is a delimiter
 * @c: The character to check
 * @delim: The list of delimiters
 *
 * Return: 1 if the character is a delimiter, 0 otherwise
 */
int is_delimiter(char c, const char *delim)
{
while (*delim)
{
if (c == *delim)
return (1);
delim++;
}
return (0);
}

