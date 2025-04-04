#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nome[30];
  int golsMarcados, golsSofridos;
} Time;

void ImprimirTimes(Time *times, int tam) {
  // Ordenar os times

  for(int j = 0; j < tam; j++) {
    for (int i = 1; i < tam; i++) {
      if (times[i - 1].golsMarcados <= times[i].golsMarcados) {
        
        // Ordenar em ordem decrescente de gols sofridos também
        if(times[i - 1].golsMarcados == times[i].golsMarcados){
          if(times[i - 1].golsSofridos <= times[i].golsSofridos){
            Time aux;

            strcpy(aux.nome, times[i].nome);
            aux.golsMarcados = times[i].golsMarcados;
            aux.golsSofridos = times[i].golsSofridos;

            strcpy(times[i].nome, times[i-1].nome);
            times[i].golsMarcados = times[i-1].golsMarcados;
            times[i].golsSofridos = times[i-1].golsSofridos;

            strcpy(times[i-1].nome, aux.nome);
            times[i-1].golsMarcados = aux.golsMarcados;
            times[i-1].golsSofridos = aux.golsSofridos;
          } else {
            break;
          }
        }
        Time aux;

        strcpy(aux.nome, times[i].nome);
        aux.golsMarcados = times[i].golsMarcados;
        aux.golsSofridos = times[i].golsSofridos;

        strcpy(times[i].nome, times[i-1].nome);
        times[i].golsMarcados = times[i-1].golsMarcados;
        times[i].golsSofridos = times[i-1].golsSofridos;

        strcpy(times[i-1].nome, aux.nome);
        times[i-1].golsMarcados = aux.golsMarcados;
        times[i-1].golsSofridos = aux.golsSofridos;
      }
    }
  }

  
  // Imprimir os times
  
  for (int i = 0; i < tam; i++){
    printf("%d - %s\n", i+1, times[i].nome);
    printf("Gols marcados: %d\n", times[i].golsMarcados);
    printf("Gols sofridos: %d\n", times[i].golsSofridos);
  }
}
int main() {
  int quantidade;
  scanf("%d", &quantidade);
  getchar();

  Time times[quantidade];

  for (int i = 0; i<quantidade; i++){
    scanf("%[^\n]", times[i].nome);
    getchar();

    scanf("%d", &times[i].golsMarcados);
    scanf("%d", &times[i].golsSofridos);
    getchar();
  }

  ImprimirTimes(times, quantidade);

  return 0;
}