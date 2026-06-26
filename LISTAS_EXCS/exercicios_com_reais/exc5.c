// ----------- [1] BIBLIOTECAS ----------- //

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>



// ----------- [2] PROTÓTIPOS ----------- //

double delta(double a, double b, double c);



// ----------- [3] MAIN ----------- //

int main(int argc, char *argv[]){

    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double c = atof(argv[3]);
    double x1 = 0, x2 = 0, i = 0;

    if (delta(a, b, c) > 0) {
        x1 = (- b - sqrt(delta(a, b, c))) / (2 * a);
        x2 = (- b + sqrt(delta(a, b, c))) / (2 * a);
        printf("Equation has 2 real solutions: x1 = %lg; x2 = %lg.\n", x1, x2);
    }

    else if (delta(a, b, c) == 0) {
        x1 = - b / (2 * a);
        printf("Equation has 1 real solution: x = %lg.\n", x1);
    }

    else {
        x1 = - b / (2 * a);
        i = sqrt((-1) * delta(a, b, c)) / (2 * a);
        printf("Equation has 2 imaginary solutions:\n");
        printf("x1 = %lg + %lgi; x2 = %lg - %lgi.\n", x1, i, x1, i);
    }

    return 0;
}



// ----------- [4] FUNÇÕES ----------- //

double delta(double a, double b, double c){
    return (b * b) - (4 * a * c);
}
