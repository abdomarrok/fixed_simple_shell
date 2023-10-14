#include "shell.h"

int _built_in(char **argument)
{
    if (strcmp(argument[0],"exit")==0)
    {
        _printstring("exit the shell \n ");
        exit(0);
    } else if(strcmp(argument[0],"cd")==0){

        if (argument[1]==NULL){
            chdir(getenv("HOME"));
        }else{
            chdir(argument[1]);
        }
    }
    return(0);
}