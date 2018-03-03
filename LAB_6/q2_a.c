#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include <unistd.h>

int main()
{
    char b[10]="sup?";
    char c[10];
    int fd[2],id;
    pipe(fd);
    id=fork();
    if(id==0)
    {
        sleep(5);
        close(fd[1]);
        read(fd[0],c,10);
        printf("child received\n");
        printf("%s\n",c);
        close(fd[0]);
    }   

    else
    {
        close(fd[0]);
        write(fd[1],b,10);
        printf("parent sending to child\n");
        wait();
        close(fd[1]);
    }   
    return 0;
}
