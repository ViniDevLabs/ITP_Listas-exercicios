#include <stdio.h>

int main() {
  int numero;

  scanf("%d", &numero);

  if (numero < 1 || numero > 100000) {
    printf("Número fora do intervalo permitido.\n");
    return 1;
  }

  int numeroReverso = 0;
  int originalNumero = numero;

  // Inverte o número para imprimir os dígitos na ordem correta
  while (numero > 0) {
    int digito = numero % 10;
    numeroReverso = numeroReverso * 10 + digito;
    numero /= 10;
  }

  // Imprime os dígitos um por um
  while (numeroReverso > 0) {
    int digito = numeroReverso % 10;
    printf("%d\n", digito);
    numeroReverso /= 10;
  }

  return 0;
}