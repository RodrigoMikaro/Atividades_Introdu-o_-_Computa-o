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
Turma: 01
Prof.: Yoshiharu
******************************************************************************/


// [0] (ANOTAÇÕES) ------------------------------------------------------------------------------------
    // Anotações utilizadas para a realização do EP3 disponíveis em: https://canva.link/fzwkrsko99d73xo


// [1] (BIBLIOTECAS) ------------------------------------------------------------------------------------

#include <math.h>
#include <stdio.h>
#include <stdlib.h> 


// [2] (IMPLEMENTAÇÃO LEITURA DE IMAGENS) ------------------------------------------------------------------------------------

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


// [3] (CONSTANTES) ------------------------------------------------------------------------------------

#define PI 3.1415926535897932384626433


// [4] (PROTÓTIPOS FUNÇÕES) ------------------------------------------------------------------------------------

void image_to_dct (int N, int IMAGE[N][N], double DCT[N][N]);
void quantize (double D[8][8], int Dtil[8][8]);
void print_codified (int Dtil[8][8]);
void unmalloc_matrix_int (int **MATRIX, int m, int n);


// [5] (MAIN) ------------------------------------------------------------------------------------

int main (int argc, char* argv[]) {

    // [5.1] (leitura da imagem em escala de cinza fornecida na linha de comando) ---------------------
    int length, height, channels_number;
    unsigned char *READ_IMAGE = stbi_load (argv[1], &length, &height, &channels_number, 1);
    
    // [5.2] (retorna "erro" se não for encontrado o arquivo) ---------------------
    if (READ_IMAGE == NULL) {
        printf ("Falha ao ler arquivo %s.\n", argv[1]);
        return 1;
    }

    // [5.3] (permite acessar a imagem por índices i e j) ---------------------
    unsigned char (*ORIGINAL_IMAGE)[length] = (unsigned char (*)[length])READ_IMAGE;

    // [5.4] (trunca a imagem para dimensões 8x8) ---------------------
    length -= length % 8;
    height -= height % 8;
    printf("%d %d\n", length, height);

    // [5.5] (cria a matriz da imagem centrada) ---------------------
    int** CENTERED_IMAGE;
    CENTERED_IMAGE = malloc (height * sizeof (int*));
    for (int i = 0; i < height; i++) {
        CENTERED_IMAGE[i] = malloc (length * sizeof (int));
    }

    // [5.6] (CENTERED_IMAGE: matriz com valores dos pixeis centrados em 0) ---------------------
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < length; j++) {
            CENTERED_IMAGE[i][j] = ORIGINAL_IMAGE[i][j] - 128;
        }
    }

    // [5.7] (libera espaço da imagem original) ---------------------
    stbi_image_free (READ_IMAGE);

    // [5.8] (percorre cada setor 8x8 da imagem) ---------------------
    for (int i = 0; i < height; i = i + 8) {
        for (int j = 0; j < length; j = j + 8) {

            // [5.8.1] (criação dos setores sem malloc - apenas 8x8) ------
            int sector[8][8];
            double dct_sector[8][8];
            int quantized_sector[8][8];

            // [5.8.2] (salva o setor atual) ------
            for (int m = 0; m < 8; m++) {
                for (int n = 0; n < 8; n++) {
                    sector[m][n] = CENTERED_IMAGE[m + i][n + j];
                }
            }

            // [5.8.3] (converte o setor para sua DCT) ------
            image_to_dct (8, sector, dct_sector);

            // [5.8.4] (converte a DCT do setor na quantizada) ------
            quantize (dct_sector, quantized_sector);

            // [5.8.5] (imprime o setor, com codificação, em uma única linha) ------
            print_codified (quantized_sector);
            printf ("\n");
        }
    }

    // [5.9] (libera espaço da imagem centrada) ---------------------
    unmalloc_matrix_int (CENTERED_IMAGE, height, length);

    // [5.10] (retorna 0, pois operação bem-sucedida) ---------------------
    return 0;
}


// [6] (FUNÇÕES) ------------------------------------------------------------------------------------

// [6.1] (tarefa 1: dct) ---------------------
void image_to_dct (int N, int IMAGE[N][N], double DCT[N][N]) {

    for (int u = 0; u < N; u++) {
        for (int v = 0; v < N; v++) {

            DCT[u][v] = 0.0;

            double cu = sqrt(2.0 / N);
            double cv = sqrt(2.0 / N);

            if (u == 0) 
                cu = sqrt(1.0 / N);
            if (v == 0)
                cv = sqrt(1.0 / N);

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    DCT[u][v] += IMAGE[i][j] * cos(((2.0 * i + 1.0) * u * PI) / (2.0 * N)) * cos(((2.0 * j + 1.0) * v * PI) / (2.0 * N));
                }
            }

            DCT[u][v] = DCT[u][v] * cu * cv;
        }
    }
}

// [6.2] (tarefa 2: quantiza) ---------------------
void quantize (double D[8][8], int Dtil[8][8]) {
  
    int Q[8][8] = {
                    {16, 10, 10, 16, 25, 41, 50, 61}, 
                    {12, 13, 14, 19, 26, 58, 60, 54},
                    {14, 12, 16, 24, 41, 56, 68, 57},
                    {14, 16, 22, 29 , 51, 87, 81, 63},
                    {18, 23, 37, 56, 69, 108, 102, 76},
                    {24, 34, 55, 64, 80, 105, 113, 92},
                    {49, 65, 78, 87, 103, 120, 120, 100},
                    {72, 93, 95, 98, 113, 100, 103, 98}
                  };

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Dtil[i][j] = (int)round (D[i][j] / Q[i][j]);

            if (Dtil[i][j] < -128) 
                Dtil[i][j] = -128;

            if (Dtil[i][j] > 127) 
                Dtil[i][j] = 127;
        }
    }
}

// [6.3] (tarefa 3: imprime_codificacao) ---------------------
void print_codified (int Dtil[8][8]) {
    int sequence[64];
    int k = 0;

    for (int s = 0; s < 15; s++) {
        
        if (s < 8) {
            int i = 0; 
            int j = s;
            
            while (j > -1) {
                sequence[k] = Dtil[i][j];
                i++;
                j--;
                k++;
            }
        }
        else {
            int j = 7;
            int i = s - j;

            while (i < 8) {
                sequence[k] = Dtil[i][j];
                i++;
                j--;
                k++;
            }
        }
    }

    printf ("%d ", sequence[0]);
    int counter = 0;

    for (int k = 1; k < 64; k++) {
        if (sequence[k] == 0) {
            counter++;
        }
        else if (sequence[k] != 0) {
            printf ("%d %d ", counter, sequence[k]);
            counter = 0;
        }
    }
    printf ("%d", counter);
}

// [6.4] (libera memória alocada com malloc) ---------------------
void unmalloc_matrix_int (int** MATRIX, int m, int n) {
    for (int i = 0; i < m; i++) {
        free (MATRIX[i]);
    }
    free (MATRIX);
}
