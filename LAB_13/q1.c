#include <stdio.h>
#include <stdlib.h>

// x = lower + rand() % (upper-lower+1);

void init_free_blocks(int array[], int n){
    for(int i=0; i<n; i++){
        int x = rand() % 1000;
        array[i] = x;
    }
}

void init_processes(int array[], int n){
    for(int i=0; i<n; i++){
        int x = 50 + rand()%(400-50 +1);
        array[i] = x;
    }
}

void print(int array[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", array[i]);
    }
    printf("\n\n");
}

void dup_array(int N[], int M[], int n){

    for(int i=0; i<n; i++)
        M[i] = N[i];

}
        

void first_fit(int FBLOCK[], int n, int PROCESSES[], int p){
    int F[n], P[p];
    dup_array(FBLOCK, F, n);
    dup_array(PROCESSES, P, p);

    printf("FIRST FIT\n");

    for(int i=0; i<n; i++)
        for(int j=0; j<p; j++){
            if(P[j] <= F[i]){
                printf("Process %d(%d) allocated to block size %d.\n",
                        j+1, P[j], F[i]);
                P[j] = 99999;
                break;
            }
        }
    printf("\n");
    for(int j=0; j<p; j++){
        if(P[j] != 99999){
            printf("Process %d(%d) is not allocated\n",j, P[j]);
        }
    }
}

void best_fit(int FBLOCK[], int n, int PROCESSES[], int p){
    int F[n], P[p];
    dup_array(FBLOCK, F, n);
    dup_array(PROCESSES, P, p);

    printf("BEST FIT\n");

    //sorting
    for(int i=0; i<n; i++)
        for(int j=0; j<n-1; j++){
            if(F[j] > F[j+1]){
                int t = F[j];
                F[j] = F[j+1];
                F[j+1] = t;
            }
        }
    printf("\n");

    for(int i=0; i<n; i++)
        for(int j=0; j<p; j++){
            if(P[j] <= F[i]){
                printf("Process %d (%d) allocated to block of size %d\n",
                        j+1, P[j], F[i]);
                P[j] = 99999;
                break;
            }
        }
    printf("\n");
    
    for(int i=0; i<p; i++)
        if( P[i] != 99999)
            printf("The process %d(%d) is not allocated.\n",i, P[i]);

}

void worst_fit(int FBLOCK[], int n, int PROCESSES[], int p){
    int F[n], P[p];
    dup_array(FBLOCK, F, n);
    dup_array(PROCESSES, P, p);
    P[4] = 5000;
    printf("WORST FIT\n");

    //sorting
    for(int i=0; i<n; i++)
        for(int j=0; j<n-1; j++){
            if(F[j] < F[j+1]){
                int t = F[j];
                F[j] = F[j+1];
                F[j+1] = t;
            }
        }
    printf("\n");

    for(int i=0; i<n; i++)
        for(int j=0; j<p; j++){
            if(P[j] <= F[i]){
                printf("Process %d (%d) allocated to block of size %d\n",
                        j+1, P[j], F[i]);
                P[j] = 99999;
                break;
            }
        }
    printf("\n");
    
    for(int i=0; i<p; i++)
        if( P[i] != 99999)
            printf("The process %d(%d) is not allocated.\n",i, P[i]);

}


int main(){

    int n;

    printf("No of free blocks: ");
    scanf(" %d", &n);
    int F[n];
    init_free_blocks(F, n);
    printf("Initialized free space:\n");
    print(F, n);

    printf("Enter no. of processes: ");
    int p;
    scanf(" %d", &p);
    int P[p];
    init_processes(P, p);
    printf("Initialized processes:\n");
    print(P, p);

    first_fit(F, n, P, p);
    best_fit(F, n, P, p);
    worst_fit(F, n, P, p);


}



