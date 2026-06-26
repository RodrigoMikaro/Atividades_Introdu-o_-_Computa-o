#include <stdlib.h>
#include <stdio.h>


int main(){
    
    int integer;
    int squared;
    scanf("%d", &integer);


    while (integer != 0) {
        squared = integer * integer;
        printf(" %d squared is: %d\n", integer, squared);
        scanf("%d", &integer);
    }
    
    return 0;

}