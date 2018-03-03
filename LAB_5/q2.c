#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main(){

    pid_t pid;
    pid = fork();
    
    if(pid < 0){
        fprintf(stderr, "Fork Failed");
        return 1;
    }
    else if(pid == 0){
        printf("Child ID: %d\n", getpid());
        printf("Parent ID: %d\n", getppid());
        printf("Child Completed.\n");
    }else{
        printf("Parent ID: %d\n", getpid());
        printf("Parent's Parent ID: %d\n", getppid());
        printf("Parent Sleeping...ZzzzZ\n");
        sleep(10);
        printf("Parent Awake.\n");
    }

    return 0;
    
}


