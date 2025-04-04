#include <stdio.h>

int ehPerfeito(int num) {
  int soma = 0;
  for (int i = 1; i < num; i++) {
    if ((num % i) == 0) {
      soma += i;
    }
  }
  if (soma == num){
    return 1;
  } else {
    return 0;
  }
}

int main() {
  int numCasos;
  int caso;

  scanf("%d", &numCasos);

  for (int i = 0; i < numCasos; i++) {
    scanf("%d", &caso);
    if (ehPerfeito(caso)) {
      printf("%d eh perfeito\n", caso);
    } else {
      printf("%d nao eh perfeito\n", caso);
    }
  }

  return 0;
}