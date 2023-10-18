#include "shell.h"

/**
 * remove_newline - Function to remove trailing newline character
 * @str: The string to process
 */
void remove_newline(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			str[i] = 0;
		}
		i++;
	}
}
