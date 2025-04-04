#include <stdio.h>

int f1 = 1, f2 = 1;
int contador = 0;
int fibonacciBetween(int n1, int n2) {
  int f3 = f1 + f2;
  if (f3 > n2) {
    return contador;
  }
  if (contador == 0 && 1 > n1){
    contador += 2;
  }
  if (f3 > n1 && f3 < n2) {
    contador++;
  }
  f1 = f2;
  f2 = f3;
  return fibonacciBetween(n1, n2);
}

int main() {
  int n1, n2;
  scanf("%d %d", &n1, &n2);

  printf("Existem %d números de fibonacci entre %d e %d", fibonacciBetween(n1, n2), n1, n2);
  
  return 0;
}