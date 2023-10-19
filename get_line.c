#include "shell.h"

/**
 * get_line - Reads input from a stream
 * @lineptr: A buffer for input
 * @n: The size of the pointer
 * @stream: The stream
 *
 * Return: number of bytes read
 */
ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
static ssize_t input;
ssize_t ret;
char c = 'x';
char *buffer = NULL;
int r;

if (input == 0)
fflush(stream);
else
return (-1);
input = 0;
buffer = malloc(sizeof(char) * 120);
if (!buffer)
return (-1);
while (c != '\n')
{
r = read(STDIN_FILENO, &c, 1);
if (r == -1 || (r == 0 && input == 0))
{
free(buffer);
return (-1);
}
if (r == 0 && input != 0)
{
input++;
break;
}
if (input >= 120)
buffer = _realloc(buffer, input, input + 1);
buffer[input] = c;
input++;
}
buffer[input] = '\0';
set_pointer(lineptr, n, buffer, input);
ret = input;
if (r != 0)
input = 0;
return (ret);
}
