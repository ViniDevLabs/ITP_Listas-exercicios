#include <stdio.h>

int verificaPontos() {
  float x1, x2, y1, y2;
  float a1, a2, b1, b2;

  scanf("%f %f %f %f", &x1, &x2, &y1, &y2);
  while (1) {
    int i = 0;
    scanf("%f %f %f %f", &a1, &a2, &b1, &b2);

    if (a1 == 0 & a2 == 0 & b1 == 0 & b2 == 0) {
      break;
    }
    if (a1 > x1 && a2 > x2 && b1 < y1 && b2 < y2) {
      printf("(<%.2f,%.2f>,<%.2f,%.2f>) contem (<%.2f,%.2f>,<%.2f,%.2f>).\n",
             x1, x2, y1, y2, a1, a2, b1, b2);
      i = 1;
    }
    if (x1 > a1 && x2 > a2 && y1 < b1 && y2 < b2) {
      printf("(<%.2f,%.2f>,<%.2f,%.2f>) contem (<%.2f,%.2f>,<%.2f,%.2f>).\n",
             a1, a2, b1, b2, x1, x2, y1, y2);
      i = 1;
    }
    if (i != 1) {
      printf("Nao posso afirmar!\n");
    }
  }

  return 0;
}

int main() {
  verificaPontos();

  return 0;
}