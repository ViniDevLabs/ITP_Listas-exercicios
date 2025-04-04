#include <stdbool.h>
#include <stdio.h>

int get_range(int n, int cells[n], int distance, int user, int *left_index, int *right_index) {
  int celulasAoAlcance = 0;

  for (int i = 0; i < n; i++) {
    bool noAlcance = (cells[i] - distance <= user) && (cells[i] + distance >= user);

    if (noAlcance && celulasAoAlcance == 0) {
      *left_index = i;
      celulasAoAlcance++;
    } else if (noAlcance && celulasAoAlcance > 0) {
      celulasAoAlcance++;
    } else if (!noAlcance && celulasAoAlcance > 0) {
      *right_index = i - 1;
      break;
    }
  }

  return celulasAoAlcance;
}

int main() {

  int nCelulas, distCelula, posUsuario;
  scanf("%d %d %d", &nCelulas, &distCelula, &posUsuario);

  int celulas[nCelulas];

  for (int i = 0; i < nCelulas; i++) {
    scanf("%d", &celulas[i]);
  }

  int left_index;
  int right_index;

  int celulasAoAlcance = get_range(nCelulas, celulas, distCelula, posUsuario, &left_index, &right_index);

  if (celulasAoAlcance == 0) {
    printf("USUARIO DESCONECTADO");
  } else {
    for (int i = left_index; i <= right_index; i++) {
      printf("%d ", celulas[i]);
    };
  }

  return 0;
}