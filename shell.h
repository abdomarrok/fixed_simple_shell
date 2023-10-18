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
int _built_in(char **argument, char **env);
void handle_shell_prompt(char **env);
void handle_command(char *buffer, char **argument, char **env);
void handle_child_process(char *path, char **argument, char *buffer,
char **env);
void remove_newline(char *str);
void tokenize_arguments(char *buffer, char **argument);
char *_get_line(char *buffer, char *bsize);

#endif
