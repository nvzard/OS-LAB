#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_t thread[2];

static void *function1(void * a)
{
int i;
for(i=0;i<10;i++)
{
printf("\n thread 1 says=%d",i);
sleep(2);
}}
static void *function2(void * b)
{
int i;
for(i=0;i<5;i++)
{
printf("\n thread 2 says=%d",i);
sleep(5);
}}




int main ()
{
pthread_create(&thread[0],NULL,function1,NULL);
pthread_create(&thread[1],NULL,function2,NULL);
pthread_exit(NULL);
return 1;
}

