#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double arctan(double x);
double angulo(int x, int y);



int main(int argc, char *argv[]){
    double a = atof(argv[1]);

    printf("%lg", arctan(a));






    return 0;
}

double angulo(int x, int y){
    return 1.0;
}



double arctan(double x){
    double result = 0.0;
    double k = 1;
    double factor = 1.0;

    while(pow(x, k) * 1.0 / k > 0.0001){
        result += factor * 1.0 * (pow(x, k) * 1.0 / k);
        factor *= -1;
        k += 2;
    }

    return result;
}