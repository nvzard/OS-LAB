#include <stdio.h>
#include <stdlib.h>

// x = lower + rand() % (upper-lower+1);

void init_sequence(int array[], int n){
    for(int i=0; i<n; i++){
        int x = rand() % 1000;
        array[i] = x;
    }
}

void init_page(int array[], int n){
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

int main(){

    int n;

    printf("No of sequence: ");
    scanf(" %d", &n);
    int F[n];
    init_sequence(F, n);
    printf("Initialized sequence:\n");
    print(F, n);

    printf("Enter no. of frames: ");
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



