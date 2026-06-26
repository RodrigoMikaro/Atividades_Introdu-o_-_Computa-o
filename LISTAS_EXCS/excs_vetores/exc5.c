#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define constante 100000

int main(int arc, char *argv[]){
    double x = atof(argv[1]);
    double y = atof(argv[2]);
    int n = atoi(argv[3]);
    double pontos[2 * n];
    double raios[constante];
    double raio = 0;
    bool tem = false;


    for(int i = 0; i < 2 * n; i++){
        scanf(" %lg", &pontos[i]);
    }

    for(int i = 0; i < constante; i = i + 2){
        raios[i] = -1;
    }

    for (int i = 0; i < 2 * n; i = i + 2){
        tem = false;
        raio = sqrt(pow(x - pontos[i], 2) + pow(y - pontos[i + 1], 2));
        for (int j = 0; j < constante; j = j + 2){
            if(raio == raios[j]){
                tem = true;
            }
        }
        if(tem == false){
            raios[i] = raio;
        }
        else{
            raios[i] = -1;
        }
    }

    printf("Raios: ");

    for (int i = 0; i < 2 * n; i = i + 2){
        if(raios[i] != -1){
            printf("(%lg) ", raios[i]);
        }
    }

    printf("\n");
    return 0;
}