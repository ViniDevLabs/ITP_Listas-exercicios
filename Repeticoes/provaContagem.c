#include <stdio.h>

int main() {
  int qtdEquipes, corrida = 0, salto = 0, lancamento = 0;
  char prova = '0';

  scanf("%d", &qtdEquipes);

  for (int i = 0; i < qtdEquipes; i++) {
    while (scanf("%c ", &prova) == 1) {
      switch (prova) {
      case 'C':
        corrida++;
        break;
      case 'S':
        salto++;
        break;
      case 'L':
        lancamento++;
        break;
      default:
        break;
      }
      if (prova == 'F') {
        break;
      }
    }
  }

  printf("%d %d %d %d", corrida, salto, lancamento,
         (corrida + salto + lancamento));

  return 0;
}