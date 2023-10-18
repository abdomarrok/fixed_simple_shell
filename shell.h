#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>


int _putchar(char c);
int _printstring(char *s);
char *place(char *path, char *argument);
char *get_location(char *command);
int _built_in(char **argument);

#endif
