#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

int main(){

    pid_t c1, c2;

    printf("Parent ID: %d\n",getpid());

    c1 = fork();
    c2 = fork();

    if(c1 == 0){

        if(c2 == 0){
            printf("C11 ID:%d\n",getpid());
        }else if(c2 > 0)
            wait();

        pid_t c12 = fork();
        if(c12 == 0){
            printf("C12 ID:%d\n",getpid());
        }else
            wait();
    }else
        wait();


    if(c2 == 0 && c1 == 0){
        printf("C2 ID:%d\n",getpid());
    }else
        wait();

    return 0;
}
