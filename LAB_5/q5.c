#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <fcntl.h>


char * filename = "q4_test_file.txt";

void main(){
    int fd1 = open(filename, O_RDONLY);
    int fd2 = open("q4_test_file_renamed.txt", O_CREAT | O_WRONLY);
    
    char* temp = (char *)malloc(1);
    int status;

    do{
        status = read(fd1, temp, 1);
        write(fd2, temp, 1);
    }while(status != 0);
  
    close(fd1);
    unlink(filename);
    close(fd2);
}
