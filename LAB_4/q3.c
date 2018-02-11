#include<sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char *test_file = "q2_test_file.txt";
char buffer[20];

int main(){

    int size;
    int fd = open(test_file, O_RDONLY);

    printf("ALL NAMES\n");
    do{
        size = read(fd, buffer, 15);
        buffer[size] = '\0';
        printf("\n%s", buffer);
        lseek(fd, 31, SEEK_CUR);
    
    }while(size != 0);

    lseek(fd, 15, SEEK_SET);
    printf("\nALL ROLL NUMBERS\n");
    do{
        size = read(fd, buffer, 15);
        buffer[size] = '\0';
        printf("\n%s", buffer);
        lseek(fd, 31, SEEK_CUR);

    }while(size != 0);

    lseek(fd, 30, SEEK_SET);
    printf("\nALL CITIES\n");
    do{

        size = read(fd, buffer, 15);
        buffer[size] = '\0';
        printf("\n%s", buffer);
    
        lseek(fd, 31, SEEK_CUR);
    
    }while(size != 0);

    close(fd);
    return 0;

} 
