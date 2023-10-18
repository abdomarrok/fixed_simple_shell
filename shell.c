#include "shell.h"

/**
 * main - Entry point of the shell program
 *
 * @argc: The number of command-line arguments.
 * @env: The array of environment variables.
 *
 * Description: This function serves as the entry point for the custom shell.
 * It continuously prompts the user for input and processes shell commands.
 *
 * Return: Always returns 0.
 */
int main(int argc, char **env)
{
	(void)argc;
	(void)env;

	while (1)
	{
		handle_shell_prompt();
	}

	return (0);
}
