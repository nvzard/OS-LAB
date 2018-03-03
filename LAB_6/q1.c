#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){

    int id, fd[2];
    pipe(fd);
    id = fork();
    if(id == 0){  //child
        close(1);
        dup(fd[1]);
        close(fd[0]);
        execlp("ls","ls", NULL);
        close(fd[1]);
    }else{          //parent
        close(0);
        dup(fd[0]);
        close(fd[1]);
        execlp("wc", "wc", NULL);
        close(fd[0]);
    }
}
