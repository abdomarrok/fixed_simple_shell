#include "shell.h"

/**
 * shell -
 * @c:
 * @argv
 * Return: 0
*/

int main(void)
{
    char *prmt = "cisfun$ ",*buffer;
    size_t size = 0;

    printf("%s",prmt);
    getline(&buffer,&size,stdin);

    printf("%s\n",buffer);
    free(buffer);
    return (0);
}