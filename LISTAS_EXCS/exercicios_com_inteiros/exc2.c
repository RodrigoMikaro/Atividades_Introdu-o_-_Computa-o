#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){

    int n = atoi(argv[1]);
    
    /* Loop:
    int sum = 0;

    for (int i = 1; i <= n; i++){
        sum += i;
    }
    */ 
    
    int sum = n / 2.0 * (n + 1);
    
    printf("All natural numbers until %d summed equal to %d\n", n, sum);

    return 0;
}