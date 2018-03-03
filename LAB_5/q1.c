#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){

    pid_t pid;
    pid = fork();


    if(pid < 0){
        fprintf(stderr, "Fork Failed");
        return 1;
    }
    else if(pid == 0){
        sleep(10);
        printf("This child is orphan id: %d\n", getpid());
    }
    else{
        printf("Parent is complete.\n");
    }
  
    return 0;
}
