#include <stdio.h>

int main() {
  int qtdLinhas, num = 1;

  scanf("%d", &qtdLinhas);

  if (qtdLinhas <= 0) {
    printf("Você entrou com %d, tente de novo na próxima", qtdLinhas);
    return 0;
  }

  for (int linha = 1; linha <= qtdLinhas; linha++) {
    for (int coluna = 1; coluna <= linha; coluna++) {
      if (num < 10) {
        if (coluna != 1) {
          printf("%3d", num);
          num++;
        } else {
          printf("%2d", num);
          num++;
        }

      } else if (num < 100) {
        if (coluna == 1) {
          printf("%2d", num);
          num++;
        } else {
          printf("%3d", num);
          num++;
        }

      } else if (num < 1000) {
        printf("%4d", num);
        num++;
      }
    }

    printf("\n");
  }

  return 0;
}