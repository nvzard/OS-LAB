#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main(){

    pid_t pid_1, pid_2;
    pid_1 = fork();
    pid_2 = fork();
    
    if(pid_1 == 0){
        pid_t pid_3;
        pid_3 = fork();
        if(pid_3 != 0){
            printf("This is C1. Child ID: %d\n", getpid());
            printf("Parent of C1: %d\n", getppid());
        }
        if(pid_3 == 0)
            printf("This is C11. Child ID: %d, Parent ID: %d\n", getpid(), getppid());
        else if(pid_2 == 0)
            printf("This is C12. Child ID: %d, Parent ID: %d\n", getpid(), getppid());
        else{
            wait();
            wait();
        }

    }
    else if(pid_2 == 0){
        printf("This is C2. Child ID: %d\n", getpid());
                
    }else{
        wait();
        wait();
        printf("Parent ID: %d\n", getpid());
    }

    return 0;
    
}


