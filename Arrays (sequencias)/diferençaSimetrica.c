#include <stdio.h>

int repetidos = 0;

int testaValores(int numero, int conjunto[], int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    if (numero == conjunto[i]) {
      repetidos++;
      return 0;
    }
  }
  return 1;
};

int main() {
  int tamN, tamM;

  scanf("%d %d", &tamN, &tamM);

  int conjuntoN[tamN], conjuntoM[tamM];
  int conjuntoDiferente[tamN + tamM];
  int resultadoTamanho = 0;

  for (int i = 0; i < tamN; i++) {
    scanf("%d", &conjuntoN[i]);
  }
  for (int j = 0; j < tamM; j++) {
    scanf("%d", &conjuntoM[j]);
  }

  // Verifica o conjunto N
  for (int k = 0; k < tamN; k++) {
    int encontrado = 0;
    for (int l = 0; l < tamM; l++) {
      if (conjuntoN[k] == conjuntoM[l]) {
        encontrado = 1;
        break;
      }
    }
    if (!encontrado) {
      if (testaValores(conjuntoN[k], conjuntoDiferente, resultadoTamanho)) {
        conjuntoDiferente[resultadoTamanho++] = conjuntoN[k];
      }
    }
  }

  // Verifica o conjunto M
  for (int k = 0; k < tamM; k++) {
    int encontrado = 0;
    for (int l = 0; l < tamN; l++) {
      if (conjuntoM[k] == conjuntoN[l]) {
        encontrado = 1;
        break;
      }
    }
    if (!encontrado) {
      if (testaValores(conjuntoM[k], conjuntoDiferente, resultadoTamanho)) {
        conjuntoDiferente[resultadoTamanho++] = conjuntoM[k];
      }
    }
  }

  for (int i = 1; i < (resultadoTamanho - repetidos); i++) {
    for (int i = 1; i < (resultadoTamanho - repetidos); i++) {
      if (conjuntoDiferente[i - 1] > conjuntoDiferente[i]) {
        int aux;
        aux = conjuntoDiferente[i];
        conjuntoDiferente[i] = conjuntoDiferente[i - 1];
        conjuntoDiferente[i - 1] = aux;
      }
    }
  }

  for (int a = 0; a < resultadoTamanho; a++) {
    printf("%d ", conjuntoDiferente[a]);
  }

  return 0;
}