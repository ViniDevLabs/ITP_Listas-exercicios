#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nome[200];
  int vitorias, empates, derrotas, golsFeitos, golsSofridos;
} Time;

int calculaPontos(Time time) { return (time.vitorias * 3) + time.empates; }
int calculaSaldo(Time time) { return time.golsFeitos - time.golsSofridos; }

void LeituraTimes(Time *times, int tam) {
  for (int i = 0; i < tam; i++) {
    scanf("%[^;]; %d %d %d %d %d", times[i].nome, &times[i].vitorias,
          &times[i].empates, &times[i].derrotas, &times[i].golsFeitos,
          &times[i].golsSofridos);
    getchar();
  }
}

void OrdenarTimes(Time *times, int tam){
  for(int i = 0; i < tam - 1; i++){
    for(int j = 0; j < tam - 1; j++){
      // j com menos pontos do que j+1
      if(calculaPontos(times[j]) < calculaPontos(times[j + 1])
      // j com menos vitórias do que j+1
      || (calculaPontos(times[j]) == calculaPontos(times[j + 1])
      && times[j].vitorias < times[j + 1].vitorias)
      // j com menos saldo do que j+1 ou igual 
      || (calculaPontos(times[j]) == calculaPontos(times[j + 1])
      && times[j].vitorias == times[j + 1].vitorias
      && calculaSaldo(times[j]) <= calculaSaldo(times[j + 1]))
      ){
        
        Time aux = times[j];
        
        strcpy(aux.nome, times[j].nome);
        // aux.vitorias = times[j].vitorias;
        // aux.empates = times[j].empates;
        // aux.derrotas = times[j].derrotas;
        // aux.golsFeitos = times[j].golsFeitos;
        // aux.golsSofridos = times[j].golsSofridos;

        times[j] = times[j + 1];
        strcpy(times[j].nome, times[j + 1].nome);
        // times[j].vitorias = times[j + 1].vitorias;
        // times[j].empates = times[j + 1].empates;
        // times[j].derrotas = times[j + 1].derrotas;
        // times[j].golsFeitos = times[j + 1].golsFeitos;
        // times[j].golsSofridos = times[j + 1].golsSofridos;

        times[j+1] = aux;
        strcpy(times[j + 1].nome, aux.nome);
        // times[j + 1].vitorias = aux.vitorias;
        // times[j + 1].empates = aux.empates;
        // times[j + 1].derrotas = aux.derrotas;
        // times[j + 1].golsFeitos = aux.golsFeitos;
        // times[j + 1].golsSofridos = aux.golsSofridos;
      }
    }
  }
}

void ImprimirTabela(Time *times, int tam) {
  
  OrdenarTimes(times, tam);
  
  printf("Tabela do campeonato:\n");
  printf("Nome| Pontos| Jogos| Vitorias| Empates| Derrotas| Gols Pro| Gols Contra| Saldo de Gols\n");
  for(int i = 0; i < tam; i++){
    printf("%s| %d| %d| %d| %d| %d| %d| %d| %d\n",
      times[i].nome,
      calculaPontos(times[i]),
      (times[i].vitorias + times[i].empates + times[i].derrotas),
      times[i].vitorias,
      times[i].empates,
      times[i].derrotas,
      times[i].golsFeitos,
      times[i].golsSofridos,
      calculaSaldo(times[i])
      );
  }

  printf("\n");
  printf("Times na zona da libertadores:\n");
  for (int i = 0; i < 6; i++){
    printf("%s\n", times[i].nome);
  }

  printf("\n");
  printf("Times rebaixados:\n");
  for (int i = tam - 1; i > tam - 5; i--){
    printf("%s\n", times[i].nome);
  }
}

int main() {
  int quantidade;
  scanf("%d", &quantidade);
  getchar();

  Time times[quantidade];

  LeituraTimes(times, quantidade);
  ImprimirTabela(times, quantidade);

  return 0;
}