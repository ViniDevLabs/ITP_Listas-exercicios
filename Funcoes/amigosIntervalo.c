#include <stdio.h>

// retorna verdadeiro se numero é divisível por divisor e falso em caso
// contrário
int testa_divisor(int numero, int divisor) {
  if ((numero % divisor) == 0) {
    return 1;
  } else {
    return 0;
  }
}

// retorna a soma dos divisores de value no intervalo [1,value)
int soma_divisores(int value) {
  int soma = 0;
  for (int i = 1; i < value; i++) {
    if (testa_divisor(value, i)) {
      soma += i;
    }
  }
  return soma;
}

// retorna verdadeiro se a é amigo de b e falso em caso contrário
int testa_amigos(int a, int b) {
  if (soma_divisores(a) == b && soma_divisores(b) == a && a != b) {
    return 1;
  } else {
    return 0;
  }
}

// recebe dois intervalos naturais L1 = [A,B] e L2 = [C,D]
// apresenta todos os valores em L1 que possuem ao menos um amigo em L2.
int main() {
  int inicialL1, fimL1, inicialL2, fimL2;
  int apresentaAmigo = 0;

  scanf("%d %d", &inicialL1, &fimL1);
  scanf("%d %d", &inicialL2, &fimL2);

  for (int i = inicialL1; i <= fimL1; i++) {
    int somaDivisores = soma_divisores(i);
    if (somaDivisores >= inicialL2 && somaDivisores <= fimL2) {
      if (testa_amigos(i, somaDivisores)) {
        printf("O %d possui um amigo!\n", i);
        apresentaAmigo = 1;
      }
    }
  }

  if (!apresentaAmigo) {
    printf("Os intervalos nao apresentam amigos!");
  }

  return 0;
}