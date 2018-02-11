#include<sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include<string.h>

char *test_file = "q2_test_file.txt";
char name[15], rollno[15], city[15];

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

void clear_buffer(){
    for(int i=0; i<25; i++)
        name[i] = rollno[i] = city[i] = ' ';
    }

int main(){

    int n;

    int fd1 = open(test_file, O_RDWR);

    printf("Enter the no of students: ");
    scanf(" %d", &n);
   
    for(int i=0; i<n; i++){
   
    clear_buffer();

    lseek(fd1, 0, SEEK_END);
    printf("##Student %d##\n", i+1);
    printf("Enter name: ");
    scanf(" %[^\n]s",name);
    write(fd1, name, 15);
    lseek(fd1, 0, SEEK_END);

    printf("Enter roll no: ");
    scanf(" %[^\n]s",rollno);
    write(fd1, rollno, 15);
    lseek(fd1, 0, SEEK_END);

    printf("Enter city: ");
    scanf(" %[^\n]s", city);
    write(fd1, city, 15);
    lseek(fd1, 0, SEEK_END);
   
    write(fd1, "\n", 1);
    lseek(fd1, 0, SEEK_END);
    
    }

    close(fd1);
    print_file();
    return 0;

} 
