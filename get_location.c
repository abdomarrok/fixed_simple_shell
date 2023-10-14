#include "shell.h"

char *place(char *path, char *arg)
{
    char *path2, *path_token, *file_path, *buffer, *delim = ":";
    path2 = strdup(path);
    path_token = strtok(path2, delim);

    file_path = malloc(strlen(arg) + strlen(path_token) + 4);

    while (path_token != NULL)
    {
        strcpy(file_path, path_token);
        strcat(file_path, "/");
        strcat(file_path, arg);
        strcat(file_path, "\0");
        if (access(file_path, X_OK) == 0)
        {
            free(path2) return (file_path);
        }
        path_token = strtok(NULL, delim);
    }
    free(file_path);
    free(path2);
    /** if(stat(arg,&buffer)==0){
          return (arg);
      }  */
    return (NULL)
}

char *get_location(char *command)
{
    char *path;

    path = getenv("PATH")

        if (path)
    {
        path = place(path, command);
        return (path);
    }
    return (NULL);
}
