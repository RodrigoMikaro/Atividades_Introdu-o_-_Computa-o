#include <stdio.h>
#include <stdlib.h>

int main() {    
    double complexes = 0.0;
    double interest_rate = 0.0;
    int months = 12;


    printf("Insira o capital: ");
    scanf("%lf", &complexes);

    printf("Insira o juros mensal (porcentagem): ");
    scanf("%lf", &interest_rate);

    printf("Determinaremos o montante de cada mês durante 1 ano, com capital inicial = %lf e juros = %lf:\n", 
    complexes, interest_rate);
    

    for (int m = 1; m <= months; m++) {
        complexes = complexes * ((interest_rate + 100.0) / 100.0);
        printf("Month %d: amount = %lf\n", m, complexes);
    }

    return 0;
}