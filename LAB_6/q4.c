#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

// ls > file.txt

int main(){

    int fd = open("file.txt", O_CREAT | O_WRONLY);
    
    close(1);
    dup(fd);
    execlp("ls", "ls", NULL);

    return 0;

}

