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
    (void)argc;
    char *prmt = "cisfun$ ", *buffer, *copy_buf, *token;
    size_t size = 0;
    ssize_t num_of_char;
    int num_of_token = 0, i;
    const char *delim = " \n";
    while (1)
    {  
        printf("%s", prmt);
        num_of_char = getline(&buffer, &size, stdin);
        if (num_of_char == -1)
        {
            printf("getting out of cisfun$ ...\n");
            return (-1);
        }
        copy_buf = malloc(sizeof(char) * num_of_char);

        if (copy_buf == NULL)
        {
            perror("failed to alloacate memory\n");
            return (-1);
        }

        strcpy(copy_buf, buffer);
        token = strtok(buffer, delim);

        while (token != NULL)
        {
            num_of_token++;
            token = strtok(NULL, delim);
        }
        num_of_token++;

        argv = malloc(sizeof(char *) * num_of_token);
        
        token = strtok(copy_buf, delim);
        for (i = 0; token != NULL; i++)
        {
            argv[i] = malloc(sizeof(char) * strlen(token));
            strcpy(argv[i], token);
            token= strtok(NULL,delim);
            printf("%s\n", argv[i]);
             
        }
    
    }

    free(buffer);
    free(copy_buf);
    free(argv);

    return (0);
}