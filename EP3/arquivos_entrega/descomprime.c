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

// [1] (BIBLIOTECAS) ------------------------------------------------------------------------------------

#include <math.h>
#include <stdio.h>
#include <stdlib.h> 


// [2] (IMPLEMENTAÇÃO ESCRITA DE IMAGENS) ------------------------------------------------------------------------------------

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"


// [3] (CONSTANTES) ------------------------------------------------------------------------------------

#define PI 3.1415926535897932384626433


// [4] (PROTÓTIPOS FUNÇÕES) ------------------------------------------------------------------------------------

void dct_to_image (int N, double DCT[N][N],int IMAGE[N][N]);
void unquantize (int Dtil[8][8], double D[8][8]);
void read_codified (int Dtil[8][8]);
void unmalloc_matrix_int (int **MATRIX, int m, int n);


// [5] (MAIN) ------------------------------------------------------------------------------------

int main (int argc, char* argv[]) {
    
    // [5.1] (leitura da largura e da altura da imagem) ---------------------
    int length, height;
    scanf("%d %d", &length, &height);

    // [5.2] (cria a matriz da imagem centrada) ---------------------
    int** CENTERED_IMAGE;
    CENTERED_IMAGE = malloc (height * sizeof (int*));
    for (int i = 0; i < height; i++) {
        CENTERED_IMAGE[i] = malloc (length * sizeof (int));
    }

    // [5.3] (percorre cada setor 8x8 da imagem) ---------------------
    for (int i = 0; i < height; i = i + 8) {
        for (int j = 0; j < length; j = j + 8) {

            // [5.3.1] (criação dos setores sem malloc - apenas 8x8) ------
            int sector[8][8];
            double dct_sector[8][8];
            int quantized_sector[8][8];

            // [5.3.2] (processos inversos) ------
            read_codified (quantized_sector);
            unquantize (quantized_sector, dct_sector);
            dct_to_image (8, dct_sector, sector);

            // [5.3.3] (salva o setor atual na imagem centrada) ------
            for (int m = 0; m < 8; m++) {
                for (int n = 0; n < 8; n++) {
                    CENTERED_IMAGE[m + i][n + j] = sector[m][n];
                }
            }
        }
    }

    // [5.4] (transforma imagem centrada na imagem original) ---------------------
    unsigned char *DISPLAYED_IMAGE = malloc(length * height);
    unsigned char (*ORIGINAL_IMAGE)[length] = (unsigned char (*)[length])DISPLAYED_IMAGE;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < length; j++) {
            int pixel = CENTERED_IMAGE[i][j] + 128;
            if (pixel > 255) {
                ORIGINAL_IMAGE[i][j] = 255;
            }
            else if (pixel < 0) {
                ORIGINAL_IMAGE[i][j] = 0;
            }
            else {
                ORIGINAL_IMAGE[i][j] = pixel;
            }
        }

    // [5.5] (salva a displayed image) ---------------------
    int stride = length;
    if (stbi_write_png (argv[1], length, height, 1, DISPLAYED_IMAGE, stride)) {
        printf ("PNG em tons de cinza salvo com sucesso em %s.\n", argv[1]);
    } else {
        printf ("Falha ao salvar PNG em tons de cinza em %s.\n", argv[1]);
    }

    // [5.6] (libera espaço da imagem centrada e da displayed image) ---------------------
    free (DISPLAYED_IMAGE);
    unmalloc_matrix_int (CENTERED_IMAGE, height, length);

    // [5.7] (retorna 0, pois operação bem-sucedida) ---------------------
    return 0;
}


// [6] (FUNÇÕES) ------------------------------------------------------------------------------------

// [6.1] (tarefa 1: dct_inverso) ---------------------
void dct_to_image (int N, double DCT[N][N],int IMAGE[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            
            double image_temp = 0.0;
        
            for (int u = 0; u < N; u++) {
                for (int v = 0; v < N; v++) {

                    double cu = sqrt(2.0 / N);
                    double cv = sqrt(2.0 / N);

                    if (u == 0) 
                        cu = sqrt(1.0 / N);
                    if (v == 0)
                        cv = sqrt(1.0 / N);

                    image_temp += cu * cv * DCT[u][v] * cos(((2.0 * i + 1.0) * u * PI) / (2.0 * N)) * cos(((2.0 * j + 1.0) * v * PI) / (2.0 * N));
                }
            }

            IMAGE[i][j] = (int)round(image_temp);
        }
    }
}

// [6.2] (tarefa 2: dequantiza) ---------------------
void unquantize (int Dtil[8][8], double D[8][8]) {
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
            D[i][j] = Dtil[i][j] * Q[i][j] * 1.0; 
        }
    }
}

// [6.3] (tarefa 3: le_codificacao) ---------------------
void read_codified (int Dtil[8][8]) {
    int counter = 1;
    int temporary_number;
    int k = 1;
    int sequence[64];

    scanf("%d", &sequence[0]);

    while (k < 64) {
        scanf("%d", &temporary_number);

        if (counter % 2 != 0) {
            for (int t = 0; t < temporary_number; t++) {
                if (k >= 64) {
                    break;
                }
                sequence[k] = 0;
                k++;
            }
            counter++;
        }
        else {
            if (k < 64) {
                sequence[k] = temporary_number;
                k++;
            }
            counter++;
        }
    }

    k = 0;

    for (int s = 0; s < 15; s++) {
        
        if (s < 8) {
            int i = 0; 
            int j = s;
            
            while (j > -1) {
                Dtil[i][j] = sequence[k];
                i++;
                j--;
                k++;
            }
        }
        else {
            int j = 7;
            int i = s - j;

            while (i < 8) {
                Dtil[i][j] = sequence[k];
                i++;
                j--;
                k++;
            }
        }
    }
}

// [6.4] (libera memória alocada com malloc) ---------------------
void unmalloc_matrix_int (int** MATRIX, int m, int n) {
    for (int i = 0; i < m; i++) {
        free (MATRIX[i]);
    }
    free (MATRIX);
}
