#include "shell.h"

int main(void)
{
    char *prmt = "($) ", *buffer = NULL;
    size_t bsize;
    ssize_t num_of_chars;

    while (1)
    {
        _printstring(prmt);
       num_of_chars= getline(&buffer, &bsize, stdin);
       if(num_of_chars==-1){
        _printstring("getting out of shell");
        return (-1);
       }
        _printstring(buffer);
    }

    free(buffer);
    return (0);
}