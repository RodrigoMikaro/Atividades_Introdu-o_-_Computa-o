#include <stdio.h>
#include <stdlib.h>

int* intersection (int A[], int B[]);

// ITEM B

int main (void) {

    int n;
    scanf ("Número n de conjuntos: %d", &n);    


// fazer


    return 0;
}

// ITEM A

int* intersection (int A[], int B[]) {
    
    int intersection_size = 0;

    for (int i = 1; i <= A[0]; i++) {
        for (int j = 1; j <= B[0]; j++) {
            if (A[i] == B[j]) {
                intersection_size += 1;
            }
        }
    }

    int C[intersection_size];
    C[0] = intersection_size;
    int k = 1;
    
    for (int i = 1; i <= A[0]; i++) {
        for (int j = 1; j <= B[0]; j++) {
            if (A[i] == B[j]) {
                C[k] = A[i];
                k++;
            }
        }
    }

    return C;

}

