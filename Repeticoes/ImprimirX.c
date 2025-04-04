#include <stdio.h>

int main() {
  int qtdLinhas;
  char letra;

  scanf("%d %c", &qtdLinhas, &letra);

  for (int linha = 1; linha < qtdLinhas; linha++) {
    for (int coluna = 1; coluna < qtdLinhas; coluna++)
      if ((linha == coluna) || (coluna == (qtdLinhas - linha)))
        printf("%c", letra);
      else
        printf(" ");
    printf("\n");
  }

  return 0;
}