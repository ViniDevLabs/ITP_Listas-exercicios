#include <stdio.h>

int verificaVetor(int nNumeros, int array[]){
  for (int i = (nNumeros - (nNumeros - 1)); i < nNumeros; i++) {
    if ((array[i] - array[i - 1]) % 2 == 0) {
    } else {
      printf("Chato");
      return 0;
    }
  }
  printf("Legal");
  return 0;
}

int main() {

  int nNumeros;
  scanf("%d", &nNumeros);

  int array[nNumeros];

  for (int i = 0; i < nNumeros; i++) {
    scanf("%d", &array[i]);
  }

  verificaVetor(nNumeros, array);

  return 0;
}