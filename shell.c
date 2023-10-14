#include "shell.h"

int main(int argc,char **env)
{
    (void)argc;
    char *prmt = "($) ", *buffer = NULL;
    char *argument[]={NULL,NULL};
    size_t bsize;
    ssize_t num_of_chars;
    pid_t child_id;
    int status,i;


    while (1)
    {
        _printstring(prmt);
       num_of_chars= getline(&buffer, &bsize, stdin);
       if(num_of_chars==-1){
        _printstring("getting out of shell");
            free(buffer);
        return (-1);
       }
       i=0;
while (buffer[i])
{
    if(buffer[i]=='\n')
    {
        buffer[i]=0;
    }
}


       argument[0]= strdup(buffer);

       child_id= fork();
        if(child_id <0){
            perror("fork error");
            free(buffer);
            return(-1);
        }else if (child_id==0){
            if(execve(argument[0],argument,env)==-1){
                _printstring("command do not exist \n ");
            };
        }else{
            wait(&status);
        }
      /* _printstring(buffer);*/
    }

    free(buffer);
    return (0);
}