#include "shell.h"

int main(void){
    char *prmt = "($) ",*buffer=NULL;
    size_t bsize;

    _printstring(prmt);
    getline(&buffer,&bsize,stdin);
    _printstring(buffer);
    free(buffer);
    return (0);

}