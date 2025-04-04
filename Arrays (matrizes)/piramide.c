#include <stdio.h>

int main() {
  int lado;
  scanf("%d", &lado);

  int piramide[lado][lado];

  for (int i = 0; i < lado; i++) {
    for (int j = 0; j < lado; j++) {
      int min = i < j ? i : j;
      int max = i > j ? i : j;
      if (min + 1 > lado - max){
        piramide[i][j] = lado - max;
      } else {
        piramide[i][j] = min + 1;
      }
    }
  }

  for (int i = 0; i < lado; i++) {
    for (int j = 0; j < lado; j++) {
      printf("%d ", piramide[i][j]);
    }
    printf("\n");
  }

  return 0;
}
