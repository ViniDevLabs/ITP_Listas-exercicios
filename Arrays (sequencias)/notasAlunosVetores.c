#include <stdio.h>

int nAlunos;

void imprimeResultados(int situacao[], double notas[], int parametro) {

  // Armazena os índices das condições
  int condicao[nAlunos];
  // Quantidade de vezes da condição
  int nCondicao = 0;

  for (int i = 0; i < nAlunos; i++) {
    if (situacao[i] == parametro) {
      condicao[nCondicao] = i;
      nCondicao++;
    }
  }

  switch (parametro) {
  case 1:
    printf("Aprovados: ");
    for (int i = 0; i < nCondicao; i++) {
      printf("%d (%.1lf)", condicao[i] + 1, notas[condicao[i]]);
      if (i != nCondicao - 1) {
        printf(", ");
      }
      if (i == nCondicao - 1) {
        printf("\n");
      }
    }
    break;
  case 0:
    printf("Recuperação: ");
    for (int i = 0; i < nCondicao; i++) {
      printf("%d (%.1lf)", condicao[i] + 1, notas[condicao[i]]);
      if (i != nCondicao - 1) {
        printf(", ");
      }
      if (i == nCondicao - 1) {
        printf("\n");
      }
    }
    break;
  case -1:
    printf("Reprovados: ");
    for (int i = 0; i < nCondicao; i++) {
      printf("%d (%.1lf)", condicao[i] + 1, notas[condicao[i]]);
      if (i != nCondicao - 1) {
        printf(", ");
      }
      if (i == nCondicao - 1) {
        printf("\n");
      }
    }
    break;
  }
}

int main() {

  scanf("%d", &nAlunos);
  int x;

  int situacaoAlunos[nAlunos];
  double notasAlunos[nAlunos];

  for (int i = 0; i < nAlunos; i++) {
    scanf("%d - %lf", &x,&notasAlunos[i]);
    if (notasAlunos[i] >= 7.0 && notasAlunos[i] <= 10) {
      situacaoAlunos[i] = 1;
    } else if (notasAlunos[i] >= 5.0 && notasAlunos[i] < 7) {
      situacaoAlunos[i] = 0;
    } else {
      situacaoAlunos[i] = -1;
    }
  }

  imprimeResultados(situacaoAlunos, notasAlunos, 1);
  imprimeResultados(situacaoAlunos, notasAlunos, 0);
  imprimeResultados(situacaoAlunos, notasAlunos, -1);

  return 0;
}