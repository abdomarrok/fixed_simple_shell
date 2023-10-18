#include "shell.h"

/**
 * _get_line - Read input from the standard input.
 *
 * Return: The string entered by the user.
 */
char *_get_line(void)
{
    static char buffer[1024];
    static int buf_pos = 0;
    static int buf_size = 0;
    char *input_str = NULL;
    int input_len = 0;
    char current_char;

    while (1)
    {
        if (buf_pos >= buf_size)
        {
            buf_size = read(STDIN_FILENO, buffer, 1024);
            buf_pos = 0;
            if (buf_size == 0)
            {
                if (input_str != NULL)
                    input_str[input_len] = '\0';
                return input_str;
            }
            else if (buf_size < 0)
            {
                perror("read");
                free(input_str);  /* Free memory before returning NULL*/
                return NULL;
            }
        }

        current_char = buffer[buf_pos];
        buf_pos++;

        if (current_char == '\n')
        {
            input_str = realloc(input_str, input_len + 1);
            if (input_str == NULL)
            {
                perror("realloc");
                return NULL;
            }
            input_str[input_len] = '\0';
            return input_str;
        }
        else
        {
            input_str = realloc(input_str, input_len + 2);  /* Increase by 2 for current_char and null-terminator*/
            if (input_str == NULL)
            {
                perror("realloc");
                return NULL;
            }
            input_str[input_len] = current_char;
            input_len++;
        }
    }
}
