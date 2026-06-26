#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]){
    
    int m = atoi(argv[1]);
    int n = atoi(argv[2]);
    double A[m][n];
    double A_copy[m][n];
    int REPEATED[m][n];

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            scanf("%lf", &A[i][j]);
            A_copy[i][j] = A[i][j];
            REPEATED[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            for (int r = 0; r < m; r++){
                for (int s = 0; s < n; s++){
                    if (A[i][j] == A_copy[r][s] && (i != r || j != s)){
                        REPEATED[i][j] = -1;
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (REPEATED[i][j] == -1){
                printf("%lf is repeated: line %d | column %d\n", A[i][j], i, j);
            }
        }
    }

    return 0;
}