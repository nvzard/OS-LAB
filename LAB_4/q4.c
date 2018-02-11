#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t  pid;
    pid = fork();   /* fork another process */

    if(pid < 0){ /* error occurred */
        fprintf(stderr, "Fork Failed");
        return 1;
    }
    else if(pid == 0) { /* child process */
        execlp("/bin/ls", "ls", NULL);
    }
    else { /* parent process */
           /* parent will wait for the child */
        wait(NULL);
        printf("Child Complete");  }
    return 0;
}
