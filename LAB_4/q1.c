#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void main(){
    int file_1 = open("q1_test_file.txt", O_RDONLY);
    
    char temp;
    int status;

    do{
        status = read(file_1, &temp, 1);
        printf("%c", temp);
    }while(status != 0);
  
    close(file_1);
}
