#include <stdio.h>
#include <stdlib.h>

int main() {
	int *arrayDinamico;
  int contador = 0;
  int auxNum;
  
  while (scanf("%d", &auxNum) != EOF) {
    if (contador == 0) {
      arrayDinamico = malloc(sizeof(int));
      arrayDinamico[0] = auxNum;
      contador++; // Já deixa pronto para o seguinte
    } else {
      arrayDinamico = realloc(arrayDinamico, sizeof(int) * (contador + 1));
      arrayDinamico[contador] = auxNum;
      contador++;
    }
  }

  for (int i = 1; i < contador; i++){
    for (int j = 1; j < contador; j++) {
      if (arrayDinamico[j - 1] >= arrayDinamico[j]) {
        int aux;
        aux = arrayDinamico[j];
        arrayDinamico[j] = arrayDinamico[j-1];
        arrayDinamico[j-1] = aux;
      }
    }
  }

  for (int i = 0; i < contador; i++) {
    printf("%d ", arrayDinamico[i]);
  }
  
	return 0;
}