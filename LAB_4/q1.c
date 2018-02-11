#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void main(){
    int file_1 = open("q1_test_file.txt", O_RDONLY);
    
    char* temp = (char *)malloc(1);
    int status;

    do{
        status = read(file_1, temp, 1);
        printf("%s", temp);
    }while(status != 0);
  
    close(file_1);
}
