#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>

//wc < file1.txt > file2.txt

int main(){

    int fd1 = open("file1.txt", O_RDONLY);
    int fd2 = open("file2.txt", O_CREAT | O_WRONLY);

    close(0);
    dup(fd1);
    close(1);
    dup(fd2);
    execlp("wc", "wc", NULL);

}
