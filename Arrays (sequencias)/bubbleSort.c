#include <stdio.h>

int main() {

  int qtdNum;
  scanf("%d", &qtdNum);
  int array[qtdNum];

  for (int i = 0; i < qtdNum; i++) {
    scanf("%d", &array[i]);
  }

  for (int i = 0; i < qtdNum; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  for (int i = 1; i < qtdNum; i++) {
    for (int i = 1; i < qtdNum; i++) {
      if (array[i - 1] > array[i]) {
        int aux;
        aux = array[i];
        array[i] = array[i - 1];
        array[i - 1] = aux;
      }
    }
    for (int i = 0; i < qtdNum; i++) {
      printf("%d ", array[i]);
    }
    printf("\n");
  }

  return 0;
}