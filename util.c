#include "shell.h"

int _putchar(char c)
{
   return(write(1, &c, 1));
}

int _printstring(char *s){
    int i = 0,c=0;
    while (s[i]) {
       
        c += _putchar(s[i++]);
    }
    return (c);

}