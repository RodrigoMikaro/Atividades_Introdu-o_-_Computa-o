#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool encaixa(int a, int b);


int main(int argc, char *argv[]){
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);




    if(encaixa(a, b)){
        printf("encaixa");
    }   
    else{
        printf("não encaixa");
    } 


    return 0;
}


bool encaixa(int a, int b){
    int new_a = a;
    int factor = 1;

    if(b > a){
        return false;
    }

    else if(b == a){
        return true;
    }

    while(new_a > 9){
        factor *= 10;
        new_a = new_a / 10;
    }

    while(a > 0){
        if(a == b){
            return true;
        }
        new_a /= 10;
    }
}


fazer