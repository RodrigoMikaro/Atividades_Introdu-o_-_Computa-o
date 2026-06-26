#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char *argv[]){

    double x = atof(argv[1]);
    int n = atoi(argv[2]);
    double cos = 0;
    int k = 2;
    double fact = 1;


    cos = 1;
    fact = 2;
    k = 2;
    for (int i = 2; i <= n; i++){
        cos += ((pow(x, k)) / fact ) * pow(-1, i - 1);
        k = k + 2;
        fact *= (k - 1) * (k);
    }
    
        
    printf("cos(%lg) = %lg.\n", x, cos);
    return 0;
}