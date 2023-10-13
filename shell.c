#include "shell.h"

/**
 * shell - A simple shell program
 *
 * @argc: The number of command-line arguments
 * @argv: An array of command-line arguments
 *
 * Return: 0 on success, or a non-zero value on failure
 */

int main(int argc, char **argv)
{
    char *prmt = "cisfun$ ", *buffer;
    size_t size = 0;
    while (1)
    {
        printf("%s", prmt);
        ssize_t num_of_char = getline(&buffer, &size, stdin);
        if (num_of_char==-1){
            printf("getting out of cisfun$ ...\n");
            return (-1);
        }
        printf("%s\n", buffer);
    }

    free(buffer);
    return (0);
}