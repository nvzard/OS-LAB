#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int total;

struct process{
    int pid;
    int at;
    int bt;
    int turnaround;
    int waiting_time;
};

void swap(struct process *xp, struct process *yp)
{
    struct process temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// A function to implement bubble sort
void bubbleSort(struct process arr[])
{
   int i, j;
   for (i = 0; i < total-1; i++)      
 
       // Last i elements are already in place   
       for (j = 0; j < total-i-1; j++) 
           if (arr[j].at > arr[j+1].at)
              swap(&arr[j], &arr[j+1]);
}

void waiting_time(struct process array[]){
    
    array[0].waiting_time = 0;
    for(int i=1; i<total; i++)
        array[i].waiting_time = array[i-1].waiting_time + array[i-1].bt;    
}

void average_times(struct process array[]){
    float wait = 0;
    for(int i=0; i<total; i++)
        wait += array[i].waiting_time;
    printf("Average waiting time: %.2f\n",wait/total);
}


void turnaround_time(struct process array[]){
    array[0].turnaround = array[0].bt;
    for(int i=1; i<total; i++)
        array[i].turnaround = array[i].waiting_time + array[i].bt;
}

void fcfs(struct process processes[]){
    bubbleSort(processes);
    waiting_time(processes);
    turnaround_time(processes);
    printf("Average waiting time: ");
    int avg_waiting=0;
    for(int i=0; i<total; i++)
        avg_waiting += processes[i].waiting_time;
    avg_waiting /= total;
    printf("%d\n", avg_waiting);
}

void print_processes(struct process array[]){
    printf("\n\n");
    printf("PID\tARRIVAL TIME\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n\n");
    for(int i=0; i<total; i++){
        printf("%d\t", array[i].pid);
        printf("%d\t\t", array[i].at);
        printf("%d\t\t", array[i].bt);
        printf("%d\t\t", array[i].waiting_time);
        printf("%d\n", array[i].turnaround);
    }
}

void input_data(struct process* p){

    printf("Input total no of processes: ");
    scanf(" %d", &total);

    for(int i=0; i<total; i++){
        p[i].pid = i+1;
        printf("\t## PROCESS %d ##\n" , p[i].pid);
        printf("Input arrival time:");
        scanf(" %d", &p[i].at);
        printf("Input burst time:");
        scanf(" %d", &p[i].bt);
    }
}

int main(){

    printf("Input total no of processes: ");
    scanf(" %d", &total);

    struct process p[total];

    for(int i=0; i<total; i++){
        p[i].pid = i + 1;
        printf("\t## PROCESS %d ##\n" , p[i].pid);
        printf("Input arrival time:");
        scanf(" %d", &p[i].at);
        printf("Input burst time:");
        scanf(" %d", &p[i].bt);
    }

    fcfs(p);
    print_processes(p);


    return 0;
}
