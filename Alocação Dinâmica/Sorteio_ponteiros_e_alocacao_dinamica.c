#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char **participantes;
  int contador = 0;
  char auxString[100];

  while (1) {
    scanf("%[^\n]", auxString);
    getchar();

    if (strcmp(auxString, "acabou") == 0) {
      break;
    }

    if (contador == 0) {
      participantes = malloc(sizeof(char *)); // Alocar memória para um array de strings
      participantes[0] = malloc(sizeof(char) * 100); // Alocar memória para a string individual
      strcpy(participantes[0], auxString);
      contador++;
    } else {
      participantes = realloc(participantes, sizeof(char *) * (contador + 1));
      participantes[contador] = malloc(sizeof(char) * 100);
      strcpy(participantes[contador], auxString);
      contador++;
    }
  }

  int seedS;
  scanf("%d", &seedS);
  srand(seedS);

  int *sorteados = malloc(contador * sizeof(int));
  for (int i = 0; i < contador; i++) {
    sorteados[i] = 0;
  }

  int numSorteados = 0;
  while (numSorteados < contador) {
    int indexParticipante = rand() % contador;

    if (sorteados[indexParticipante] == 0) {
      printf("%s\n", participantes[indexParticipante]);
      sorteados[indexParticipante] = 1;
      numSorteados++;
    }
  }

  return 0;
}