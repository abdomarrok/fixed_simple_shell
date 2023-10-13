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

  printf("%s", prmt);
  getline(&buffer, &size, stdin);

  printf("%s\n", buffer);
  free(buffer);
  return (0);
}