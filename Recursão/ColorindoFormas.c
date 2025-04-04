#include <stdio.h>
#include <string.h>

void colorirFormas(int m, int n, char mat[m][n], int i, int j,
                   char charPreencher, int jaFoi[m][n], char original) {

  // abaixo
  if (i + 1 < m && mat[i + 1][j] == original && jaFoi[i + 1][j] == 0) {
    jaFoi[i][j] = 1;
    colorirFormas(m, n, mat, i + 1, j, charPreencher, jaFoi, original);
    jaFoi[i][j] = 0;
    mat[i][j] = charPreencher;
    mat[i + 1][j] = charPreencher;
  }
  
  // acima
  if (i - 1 >= 0 && mat[i - 1][j] == original && jaFoi[i - 1][j] == 0) {
    jaFoi[i][j] = 1;
    colorirFormas(m, n, mat, i - 1, j, charPreencher, jaFoi, original);
    jaFoi[i][j] = 0;
    mat[i][j] = charPreencher;
    mat[i - 1][j] = charPreencher;
  }

  // direita
  if (j + 1 < n && mat[i][j + 1] == original && jaFoi[i][j + 1] == 0) {
    jaFoi[i][j] = 1;
    colorirFormas(m, n, mat, i, j + 1, charPreencher, jaFoi, original);
    jaFoi[i][j] = 0;
    mat[i][j] = charPreencher;
    mat[i][j + 1] = charPreencher;
  }

  // esquerda
  if (j - 1 >= 0 && mat[i][j - 1] == original && jaFoi[i][j - 1] == 0) {
    jaFoi[i][j] = 1;
    colorirFormas(m, n, mat, i, j - 1, charPreencher, jaFoi, original);
    jaFoi[i][j] = 0;
    mat[i][j] = charPreencher;
    mat[i][j - 1] = charPreencher;
  }
}

int main() {
  int m, n;
  scanf("%d %d", &m, &n);
  char mat[m][n];
  int jaFoi[m][n];
  memset(jaFoi, 0, sizeof(jaFoi));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf(" %c", &mat[i][j]);
    }
  }

  int posI, posJ;
  scanf("%d %d", &posI, &posJ);

  char charPreencher;
  scanf(" %c", &charPreencher);

  char original = mat[posI][posJ];

  colorirFormas(m, n, mat, posI, posJ, charPreencher, jaFoi, original);

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("%c", mat[i][j]);
    }
    printf("\n");
  }

  return 0;
}