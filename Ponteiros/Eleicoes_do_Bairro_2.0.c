#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int id, nVotos;
  char nome[30];
} Party;

int VotoValido(int nChapas, Party chapas[nChapas], int id) {
  for (int i = 0; i < nChapas; i++) {
    if (chapas[i].id == id) {
      return i;
    }
  }

  return -1;
};

int compute_votes(int num_votes, int votes[num_votes], int num_parties, Party parties[num_parties], Party *most_voted, Party *second_most_voted) {
  int votosValidos = 0;

  for (int i = 0; i < num_votes; i++) {
    int indexChapa = VotoValido(num_parties, parties, votes[i]);
    if (indexChapa != -1) {
      votosValidos++;
      parties[indexChapa].nVotos++;
    }
  }

  *most_voted = parties[0], *second_most_voted = parties[0];

  for (int i = 0; i < num_parties; i++) {
    if (parties[i].nVotos >= most_voted->nVotos) {
      *most_voted = parties[i];
    }
  }

  for (int i = 0; i < num_parties; i++) {
    if (parties[i].id != most_voted->id &&
        parties[i].nVotos >= second_most_voted->nVotos) {
      *second_most_voted = parties[i];
    }
  }

  return votosValidos;
}

int main() {

  int nChapas;
  scanf("%d", &nChapas);

  Party chapas[nChapas];
  for (int i = 0; i < nChapas; i++) {
    chapas[i].nVotos = 0;
    scanf("%d %s[^\n]", &chapas[i].id, chapas[i].nome);
    getchar();
  }

  int nVotos;
  scanf("%d", &nVotos);

  int votos[nVotos];
  for (int i = 0; i < nVotos; i++) {
    scanf("%d ", &votos[i]);
  }

  Party maisVotado, segundoMaisVotado;

  int votosValidos = compute_votes(nVotos, votos, nChapas, chapas, &maisVotado, &segundoMaisVotado);

  printf("VENCEDOR: %s (%d votos = %.2f%%)\nVICE: %s (%d votos = %.2f%%)",
         maisVotado.nome, maisVotado.nVotos,
         maisVotado.nVotos / (votosValidos * 1.0) * 100.0,
         segundoMaisVotado.nome, segundoMaisVotado.nVotos,
         segundoMaisVotado.nVotos / (votosValidos * 1.0) * 100.0);

  return 0;
}