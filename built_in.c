#include "shell.h"

int _built_in(char **argument)
{
    if (strcmp(argument[0],"exit")==0)
    {
        _printstring("exit the shell");
        exit(0);
    }
    return(0);
}