#include "shell.h"

/**
 * is_delimiter - Check if a character is a delimiter
 * @c: The character to check
 * @delim: The list of delimiters
 *
 * Return: 1 if the character is a delimiter, 0 otherwise
 */
int is_delimiter(char c, const char *delim) {
    while (*delim) {
        if (c == *delim)
            return 1;
        delim++;
    }
    return 0;
}

/**
 * tokenize_arguments - Function to tokenize command arguments
 * @buffer: The input command buffer
 * @argument: An array of arguments for the command
 */
void tokenize_arguments(char *buffer, char **argument) {
    int j = 0;
    int in_word = 0; 
    char *arg_start = buffer; 

    while (*buffer) {
        if (!is_delimiter(*buffer, " \n")) {
            if (!in_word) {
                arg_start = buffer;  
                in_word = 1;
            }
        } else {
            if (in_word) {
                *buffer = '\0';  
                argument[j++] = arg_start;
                in_word = 0;
            }
        }
        buffer++;
    }

    if (in_word) {
        argument[j] = arg_start; 
        j++;
    }

    argument[j] = NULL; 
}
