/*
  Lê uma imagem e imprime a luminância de cada pixel na saída padrão, truncando a
  imagem para que as dimensões sejam múltiplas de 8.

  ./image_to_pixels entrada.png > pixels.txt
*/

#include <stdio.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main(int argc, char *argv[]) {
    int largura, altura, num_canais;

    /*
      O número 1 no quinto parâmetro de stbi_load diz para converter a imagem
      para tons de cinza (1 canal de cor) se necessário.
    */
    unsigned char *img = stbi_load(argv[1], &largura, &altura, &num_canais, 1);
    if (img == NULL) {
        printf("Falha ao ler arquivo %s.\n", argv[1]);
        return 1;
    }

    /* É útil poder acessar o vetor img como uma matriz altura x largura. */
    unsigned char (*mat)[largura] = (unsigned char (*)[largura])img;

    /* Para facilitar o EP, truncaremos a imagem para ter dimensões múltiplas
       de 8 */
    largura -= largura % 8;
    altura -= altura % 8;
    printf("%d %d\n", largura, altura);

    for (int i = 0; i < altura; i++) {
        printf("%d", mat[i][0] - 128);
        for (int j = 1; j < largura; j++)
            printf(" %d", mat[i][j] - 128);
        printf("\n");
    }

    /* O stbi_load aloca memória internamente (note que img é um ponteiro!).
       Precisamos desalocar essa memória usando uma rotina específica, ao invés
       de usar free(img). */
    stbi_image_free(img);
    return 0;
}
