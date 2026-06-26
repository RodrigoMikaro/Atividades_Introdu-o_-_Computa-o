#include <stdio.h>
#include <stdlib.h>

int main(void){

    char c;
    int t = 0;

    scanf("%c", &c);

    while (c != '.'){
        t++;
        scanf("%c", &c);
    }

    printf("%d \n", t);
    return 0;
}