#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_t thread[2];

static void *function1(void * a){

    int i;
    for(i=1;i<=10;i++){
        //printf("\n thread 1 says=%d",i);

        printf("\n %d", i);
        //int temp = i;
        //write(1, temp, 1); 
        sleep(1);
    }

    }

static void *function2(void * b){    
        int i;
        for(i=0;i<5;i++){
          //printf("\n thread 2 says=%c",i+65);

            sleep(2);
            //char temp = i+65;
            //write(1 , temp, 1);
            printf("\n %c", i+65);
        }
    }




int main(){

    pthread_create(&thread[0],NULL,function1,NULL);
    pthread_create(&thread[1],NULL,function2,NULL);
    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);
    pthread_exit(NULL);
    return 1;
}
