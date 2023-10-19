#ifndef SHELL_H
#define SHELL_H

#define MAX_ARGS 10

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

extern char **environ;


char *_strcpy(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
char *_strtok(char *str, const char *delim);
char *_strconcat(const char *s1, const char *s2);
int _strlen(const char *s);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);

void *_realloc(void *ptr, unsigned int old, unsigned int new);
void set_pointer(char **lineptr, size_t *n, char *buffer, size_t b);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);

/* Shell interface */
char **get_input(void);

char *_getenv(const char *name);
int execute_command(char **args);
void run_command(char **args);
void exit_shell(char **args);

/* Converts string to integer */
int strTOint(const char *str);
int env_builtin(void);
/* Function execution */
void  updateEnvironmentVariable(char **args);
void removeEnvironmentVariable(char **args);
void free_arguments(char **args);
char *customGetEnvironmentVariable(const char *var);
void cd_builtin(char **args);

/*  directories */
int cd_handler(char **args);
int handle_previous_directory(void);
int get_current_directory(char *current_directory);
int change_directory(const char *path);
int update_directory_env_variables(const char *old_directory,
const char *new_directory);


char **add_argument(char **args, char *arg, size_t *arg_count);
ssize_t read_user_input(char **input, size_t *len);
char **parse_input(char *input);
int custom_setenv(const char *name, const char *value);
int execute_external_command(char **args);
void execute_user_command(char **args);

int _setenv(const char *name, const char *value, int overwrite);

char *_strconcats(const char *str1, const char *str2);

#endif
