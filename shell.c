#include "shell.h"

int main(int argc, char **env)
{
	(void)argc;
    
	while (1)
	{
		handle_shell_prompt();
	}

	return (0);
}
