/******************************************************************************
Ao preencher esse cabeçalho com o meu nome e o meu número USP, declaro que sou
o único autor e responsável por esse programa. Todas as partes originais desse
Exercício-Programa (EP) foram desenvolvidas e implementadas por mim seguindo
as instruções desse EP e que portanto não constituem desonestidade acadêmica
ou plágio.
Declaro também que sou responsável por todas as cópias desse programa e que eu
não distribuí ou facilitei a sua distribuição. Estou ciente que os casos de
plágio e desonestidade acadêmica serão tratados segundo os critérios
divulgados na página da disciplina.
Entendo que EPs sem assinatura não serão corrigidos e, ainda assim, poderão
ser punidos por desonestidade acadêmica.
Nome : Rodrigo Francisco Pettinati Mikaro
NUSP : 16899844
Turma: 01 - Eng. Computação
Prof.: Yoshiharu Kohayakawa
******************************************************************************/



// ---------------- [1] BIBLIOTECAS ---------------- //
    
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <math.h>
    #include <complex.h>



// ---------------- [2] CONSTANTES ---------------- //
    
    #define EPSILON 1e-16 // Itera até que o valor de z mude por no máximo EPSILON
    #define ITER_MAX 10000 // Itera no máximo ITER_MAX vezes
    #define TOLERANCIA_1 1e-13 // Tolerância utilizada no teste p(z) = 0
    #define TOLERANCIA_2 1e-12 // Tolerância para verificar se raiz é nova ou igual
    // O valor de p(z) deve ser no máximo TOLERANCIA_1
    #define N 256


    
// ---------------- [3] PROTÓTIPOS FUNÇÕES ---------------- //
    
    double complex eval_poly(double a[], int grau, double complex x);
    double complex root(double a[], double b[], double complex x0, bool *succ, int grau);
    double complex eval_poly_verific(double a[], int grau, double complex x);



// ---------------- [4] MAIN ---------------- //

    int main(int argc, char* argv[]) {
       
        // ------- [4.1] Leitura da entrada padrão de p(x) & p'(x) -------
            double a[501] = {0}; // p(x) = (a[0]) + (a[1] * x^1) + ... + (a[500] * x^500)
            double b[500] = {0}; // p'(x) = (a[1]) + (2 * a[2] * x^1) + ... + (500 * a[500] * x^499)
            int grau_lido = 0;
            int maior_grau = 0;
            double coeficiente_lido = 0.0;
            while(scanf("%d %lf", &grau_lido, &coeficiente_lido) != EOF){
                if(grau_lido > maior_grau)
                    maior_grau = grau_lido;
                a[grau_lido] = coeficiente_lido;
            }
            for(int i = 0; i < maior_grau; ++i)
                b[i] = (i + 1) * a[i + 1];

        // ------- [4.2] Variáveis succ (succeed), roots_found, e root[] -------
            bool succ;
            int roots_found = 0;
            double complex roots[maior_grau + 1];

        // ------- [4.3] Geração do conjunto de x0s -------
            double complex x0[(N + 1) * (N + 1)];
            int j = 0; // contador
            for(int r = 0; r <= N; ++r){
                for(int s = 0; s <= N; ++s){
                    double parte_real = -2.0 + (4.0 * r) / N;
                    double parte_imag = -2.0 + (4.0 * s) / N;
                    x0[j] = parte_real + parte_imag * I;
                    ++j;
                }
            }
        
        // ------- [4.4] Procurar raiz para cada x0 (temos j desses x0) -------
            for(int i = 0; i < j; ++i){
                succ = false;

                /* -- (4.4.1) Encontra (ou não) a raiz p(x) = 0) -- */
                    double complex r = root(a, b, x0[i], &succ, maior_grau);
                
                    for(int k = 0; k < roots_found; ++k){
                        if((cabs(creal(r) - creal(roots[k])) <= TOLERANCIA_2) && (cabs(cimag(r) - cimag(roots[k])) <= TOLERANCIA_2)){
                            succ = false;
                            break;
                        }
                    }
                /* -- (4.4.2) Imprime a raiz (partes imag + real) -- */
                    if (succ) {
                        roots[roots_found] = r;
                        roots_found++;
                        if(creal(r) >= 0)
                            printf(" %.12lf ", creal(r));
                        else if(creal(r) < 0)
                            printf("%.12lf ", creal(r));
                        if(cimag(r) >= 0)
                            printf(" %.12lf\n", cimag(r));
                        else if(cimag(r) < 0)
                            printf("%.12lf\n", cimag(r));
                    }
            }

        // ------- [4.5] Fim do Main -------
            return 0;
    }



// ---------------- [5] FUNÇÕES ---------------- //
    
    // ------- [5.1] (ROOT) Encontra uma raiz a partir de um x0 -------
        double complex root(double a[], double b[], double complex x0, bool *succ, int grau) {
            double complex x1;

            for (int i = 0; i < ITER_MAX; ++i) {
                double complex derivada = eval_poly(b, grau - 1, x0);
                
                // Caso derivada seja muito próxima de 0:
                if (cabs(derivada) < EPSILON) {
                    *succ = false;
                    return x0; 
                }

                x1 = x0 - eval_poly(a, grau, x0) / derivada;
                if (cabs(x1 - x0) < EPSILON)
                    break;
                x0 = x1;
            }
            double p_verific = eval_poly_verific(a, grau, x1);
            *succ = cabs(eval_poly(a, grau, x1)) <= TOLERANCIA_1 * p_verific;
            return x1;
        }

    // ------- [5.2] (EVAL POLY) Calcula o valor do polinômio p(x) para um x dado -------
        double complex eval_poly(double a[], int grau, double complex x) {
            double complex s = 0;
            for (int i = grau; i >= 0; --i) {
                s = s * x + a[i];
            }
            return s;
        }

    // ------- [5.3] (EVAL POLY VERIFICATION) Calcula p(|x|) com todos coeficiente em módulo também para depois comparar com [5.2] -------
        double complex eval_poly_verific(double a[], int grau, double complex x) {
            double complex s = 0;
            for (int i = grau; i >= 0; --i) {
                s = s * cabs(x) + cabs(a[i]);
            }
            return s;
        }
