#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

char *test_file = "q2_test_file.txt";
char buffer[15];

void print_file(){

    printf("\n\n#$#$#$#$FILE OUTPUT#$#$#$\n\n");

    int file = open(test_file, O_RDONLY);
    char temp;
    int status;
    do{
        status = read(file, &temp, 1);
        printf("%c", temp);
    }while(status != 0);
    close(file);
}

int main(){

    int n;

    int fd1 = open(test_file, O_WRONLY);

    printf("Enter the no of students: ");
    scanf(" %d", &n);
   
    for(int i=0; i<n; i++){
   
    //lseek(fd1, 0, SEEK_END);
    printf("##Student %d##\n", i+1);
    printf("Enter name: ");
    scanf(" %[^\n]%*c", buffer);
    write(fd1, buffer, strlen(buffer));

    for(int i=0; i<15-strlen(buffer); i++)
        write(fd1, " ", 1);

    printf("Enter roll no: ");
    scanf(" %[^\n]%*c",buffer);
    write(fd1, buffer, strlen(buffer));

    for(int i=0; i<15-strlen(buffer); i++)
        write(fd1, " ", 1);

    printf("Enter city: ");
    scanf(" %s", buffer);
    write(fd1, buffer, strlen(buffer));

    for(int i=0; i<15-strlen(buffer); i++)
        write(fd1, " ", 1);
   
    write(fd1, "\n", 1);
    //lseek(fd1, 0, SEEK_END);
    
    }

    close(fd1);
    print_file();
    return 0;

} 
