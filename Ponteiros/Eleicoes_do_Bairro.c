#include <stdbool.h>
#include <stdio.h>

int contagem(int nVotos, int votos[nVotos], int num) {
  int qtd = 0;
  for (int i = 0; i < nVotos; i++) {
    if (votos[i] == num) {
      qtd++;
    }
  }

  return qtd;
}

void compute_votes(int n, int votes[n], int *most_voted, int *second_most_voted) {
  for (int i = 1; i < 11; i++) {
    if (contagem(n, votes, i) > contagem(n, votes, *most_voted)) {
      *most_voted = i;
    }
  }

  for (int i = 1; i < 11; i++) {
    if (i != *most_voted &&
        (contagem(n, votes, i) > contagem(n, votes, *second_most_voted))) {
      *second_most_voted = i;
    }
  }
}

int main() {

  int nVotos;
  scanf("%d", &nVotos);

  int votos[nVotos];
  for (int i = 0; i < nVotos; i++) {
    scanf("%d ", &votos[i]);
  }

  int maisVotado = 0, segundoMaisVotado = 0;

  compute_votes(nVotos, votos, &maisVotado, &segundoMaisVotado);

  printf("%d %d", maisVotado, segundoMaisVotado);

  return 0;
}