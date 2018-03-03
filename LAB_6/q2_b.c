#include<stdio.h>
#include<sys/types.h>
#include <unistd.h>

int main(){

    char b[10]="sup?";
    char c[10];
    int fd[2],id;
    pipe(fd);
    id=fork();
    if(id==0){
        //sleep(5);
        close(fd[0]);
        write(fd[1],b,10);
        printf("child sending to parent\n");
        close(fd[1]);
    }
    else{
        wait();
        close(fd[1]);
        read(fd[0],c,10);
        printf("parent received\n");
        printf("%s\n",c);
        close(fd[0]);
    }

    return 0;
}
