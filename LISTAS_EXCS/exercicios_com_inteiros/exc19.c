#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);
    int temporary;

    if (a > b) {
        temporary = a;
        a = b; 
        b = temporary;
    }

    if (b > c) {
        temporary = b;
        b = c;
        c = temporary;
    }

    if (a > b) {
        temporary = a;
        a = b;
        b = temporary;
    }

    printf("%d %d %d\n", a, b, c);

    return 0;
}