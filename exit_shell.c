#include "shell.h"

void exit_shell(char **args)
{
	int i;

	if (args[1] != NULL)
	{
		int exit_status = strTOint(args[1]);

		for (i = 0; args[i] != NULL; i++)
		{
			free(args[i]);
		}
		free(args);
		exit(exit_status);
	}

	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}
	free(args);
	exit(0);
}
/**
 * strTOint - Converts string to integer
 * @str: String to be converted
 *
 * Return: result * the sign
 * this tells us if the integer converted to is +ve or -ve
*/

int strTOint(const char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i = 1;
	}

	for (; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = (result * 10 + (str[i] - '0'));
		} else
		{
			/* Handle invalid characters here if needed */
			return (0); /* Return 0 for invalid input */
		}
	}

	return (result * sign);
}
