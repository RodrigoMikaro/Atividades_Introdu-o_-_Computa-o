/*
  Para imagens tons de cinza, desfaz o que o image_to_pixels.c faz (a menos do
  truncamento para as dimensões da imagem serem múltiplas de 8).

  ./pixels_to_png saida.png < pixels.txt
*/

#include <stdio.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main(int argc, char *argv[]) {
    int largura, altura;
    scanf("%d %d", &largura, &altura);

    unsigned char *img = malloc(largura * altura);
    unsigned char (*mat)[largura] = (unsigned char (*)[largura])img;
    for (int i = 0; i < altura; i++)
        for (int j = 0; j < largura; j++) {
            int tmp;
            scanf("%d", &tmp);
            mat[i][j] = tmp + 128;
        }

    /* Vamos escrever a imagem em tons de cinza. O "stride" de uma imagem é o
       número de bytes necessários para representar uma linha da imagem. Como
       nossas imagens são em tons de cinza, precisamos de um byte por pixel da
       linha, e portanto de "largura" bytes para representar uma linha. */
    int stride = largura;
    /*
      O quarto parâmetro é o número de canais de cor por pixel no array img.
      Como queremos salvar apenas a luminância, a imagem será em tons de cinza.
    */
    if (stbi_write_png(argv[1], largura, altura, 1, img, stride)) {
        printf("PNG em tons de cinza salvo com sucesso em %s.\n", argv[1]);
    } else {
        printf("Falha ao salvar PNG em tons de cinza em %s.\n", argv[1]);
    }

    free(img);
    return 0;
}
