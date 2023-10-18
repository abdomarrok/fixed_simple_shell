#include "shell.h"

/**
 * _putchar - Writes a single character to the standard output.
 * @c: The character to be written.
 *
 * Return: On success, 1. On error, -1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printstring - Prints a string to the standard output.
 * @s: The string to be printed.
 *
 * Return: The number of characters printed.
 */
int _printstring(char *s)
{
	int i = 0, c = 0;
	while (s[i])
	{
		c += _putchar(s[i++]);
	}
	return (c);
}
