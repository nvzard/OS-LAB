#include<sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char *test_file = "q2_test_file.txt";
char buffer[20];

int main(){

    printf("NAME           ROLL_NO        CITY\n\n");

    int status, size;
    int fd = open(test_file, O_RDONLY);

    do{
    
    size = read(fd, buffer, 15);
    buffer[size] = '\0';
    printf("%s", buffer);
    
    //lseek(fd, 15, SEEK_CUR);
    
    size = read(fd, buffer, 15);
    buffer[size] = '\0';
    printf("%s", buffer);
    
    size = read(fd, buffer, 15);
    buffer[size] = '\0';
    printf("%s", buffer);

    
    }while(size != 0);

    close(fd);
    return 0;

} 
