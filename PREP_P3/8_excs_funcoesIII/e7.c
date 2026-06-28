#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ACCEPTABLE_DIFFERENCE 1E-10

bool is_contained (int n, int m, double A[n], double B[m]);

int main (int argc, char* argv[]) {
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);

    double A[n];
    double B[m];

    for (int i = 0; i < n; i++) {
        scanf ("%lf", &A[i]);
    }

    for (int i = 0; i < m; i++) {
        scanf ("%lf", &B[i]);
    }
    
    if (is_contained (n, m, A, B) && is_contained (m, n, B, A)) {
        printf("A equals B.\n");
    }
    else {
        printf("A does not equal B.\n");
    }

    return 0;
}

bool is_contained (int n, int m, double A[n], double B[m]) {

    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < m; j++) {
            if (fabs (A[i] - B[j]) <= ACCEPTABLE_DIFFERENCE) {
                found = true;
                break;
            }
        }
        if (found == false) {
            return false;
        }
    }

    return true;
}