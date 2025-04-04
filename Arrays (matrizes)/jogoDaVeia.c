#include <stdio.h>

char tabuleiro[3][3];

int testaJogada(int linha, int coluna, char simbolo) {
  if (linha >= 4 || linha <= 0 || coluna >= 4 || coluna <= 0 ||
      tabuleiro[linha - 1][coluna - 1] == 'X' ||
      tabuleiro[linha - 1][coluna - 1] == 'O') {
    return -1;
  }

  char original = tabuleiro[linha - 1][coluna - 1];
  tabuleiro[linha - 1][coluna - 1] = simbolo;

  for (int i = 0; i < 3; i++) {
    if ((tabuleiro[i][0] == 'X' && tabuleiro[i][1] == 'X' &&
         tabuleiro[i][2] == 'X') ||
        (tabuleiro[i][0] == 'O' && tabuleiro[i][1] == 'O' &&
         tabuleiro[i][2] == 'O')) {
      tabuleiro[linha - 1][coluna - 1] = original;
      return 1;
    } else if ((tabuleiro[0][i] == 'X' && tabuleiro[1][i] == 'X' &&
                tabuleiro[2][i] == 'X') ||
               (tabuleiro[0][i] == 'O' && tabuleiro[1][i] == 'O' &&
                tabuleiro[2][i] == 'O')) {
      tabuleiro[linha - 1][coluna - 1] = original;
      return 1;
    }
  }

  if ((tabuleiro[0][0] == 'X' && tabuleiro[1][1] == 'X' &&
       tabuleiro[2][2] == 'X') ||
      (tabuleiro[0][0] == 'O' && tabuleiro[1][1] == 'O' &&
       tabuleiro[2][2] == 'O')) {
    tabuleiro[linha - 1][coluna - 1] = original;
    return 1;
  }
  if ((tabuleiro[0][2] == 'X' && tabuleiro[1][1] == 'X' &&
       tabuleiro[2][0] == 'X') ||
      (tabuleiro[0][2] == 'O' && tabuleiro[1][1] == 'O' &&
       tabuleiro[2][0] == 'O')) {
    tabuleiro[linha - 1][coluna - 1] = original;
    return 1;
  }

  tabuleiro[linha - 1][coluna - 1] = original;
  return 0;
}

int main() {

  int nJogadas;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3 + 1; j++) {
      scanf("%c", &tabuleiro[i][j]);
    }
  }

  scanf("%d", &nJogadas);

  for (int i = 0; i < nJogadas; i++) {
    int linha, coluna;
    char simbolo;

    scanf("%d %d %c", &linha, &coluna, &simbolo);
    int jogada = testaJogada(linha, coluna, simbolo);

    if (jogada == 1) {
      printf("Boa jogada, vai vencer!\n");
    } else if (jogada == 0) {
      printf("Continua o jogo.\n");
    } else if (jogada == -1){
      printf("Jogada inválida!\n");
    }
  }

  return 0;
}