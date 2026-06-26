#include <stdio.h>
#include <stdlib.h>

int main(void){
    char *a, *b;
    a = "abacate";
    b = "uva";
    if (a < b)
        printf("%s vem antes de %s no dicionário", a, b);
    else
        printf("%s vem depois de %s no dicionário", a, b);

    
    return 0;
}