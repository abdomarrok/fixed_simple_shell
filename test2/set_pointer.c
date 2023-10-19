#include "shell.h"

/**
 * set_pointer - sets the line pointer
 * @lineptr: A buffer for input
 * @n: The size of the pointer
 * @buffer: The string to assign
 * @b: The size of the buffer
 */
void set_pointer(char **lineptr, size_t *n, char *buffer, size_t b)
{
	if (*lineptr == NULL)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buffer;
	}
	else if (*n < b)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}