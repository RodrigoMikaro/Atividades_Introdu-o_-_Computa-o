#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int contadigitos(int n, int d);

int main(int argc, char* argv[]){
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int a_org = a;
    int b_org = b;
    int digito = 0;
    bool is_permutation = true;
    int contador_b = 0;
    int contador_a = 0;

    while(a > 0){
        a = a / 10;
        contador_a++;
    }

    while(b > 0){
        b = b / 10;
        contador_b++;
    }

    if(contador_b != contador_a){
        printf("%d is NOT a permutation of %d.\n", a_org, b_org);
        return 0;
    }
    
    a = a_org;
    b = b_org;

    while(a > 0 && is_permutation == true){
        digito = a % 10;
        a = a / 10;

        if(contadigitos(a_org, digito) != contadigitos(b_org, digito)){
            is_permutation = false;
        }
    }

    if(is_permutation == true){
        printf("%d is permutation of %d.\n", a_org, b_org);
    }
    else{
        printf("%d is NOT a permutation of %d.\n", a_org, b_org);
    }

    
    return 0;
}


int contadigitos(int n, int d){
    int d_org = d;
    int digito = 0;
    int contador = 0;
    while(n != 0){
        digito = n % 10;
        n = n / 10;
        if(digito == d_org){
            contador++;
        }
    }

    return contador;
}