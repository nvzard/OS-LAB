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
           if (arr[j].bt > arr[j+1].bt)
              swap(&arr[j], &arr[j+1]);
}

void waiting_time(struct process array[]){
    array[0].waiting_time = 0;
    for(int i=1; i<total; i++)
        array[i].waiting_time = array[i-1].waiting_time + array[i-1].bt;    
}

void turnaround_time(struct process array[]){
    array[0].turnaround = array[0].bt;
    for(int i=1; i<total; i++)
        array[i].turnaround = array[i].waiting_time + array[i].bt;
}

void sjf(struct process processes[]){
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
    for(int i=0; i<total; i++){
        printf("PROCESS ID: %d\n", array[i].pid);
        printf("ARRIVAL TIME: %d\n", array[i].at);
        printf("BURST TIME: %d\n", array[i].bt);
        printf("WAITING TIME: %d\n", array[i].waiting_time);
        printf("TURNAROUND TIME: %d\n\n", array[i].turnaround);
    }
}

int main(){

    printf("Input total no of processes: ");
    scanf(" %d", &total);

    struct process p[total];

    for(int i=0; i<total; i++){
        p[i].pid = i+1;
        printf("\t## PROCESS %d ##\n" , p[i].pid);
        printf("Input arrival time:");
        scanf(" %d", &p[i].at);
        printf("Input burst time:");
        scanf(" %d", &p[i].bt);
    }

    sjf(p);
    print_processes(p);


    return 0;
}
