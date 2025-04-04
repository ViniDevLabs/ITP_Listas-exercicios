#include <stdio.h>

void collatzConjecture(int n) {
  printf("%d ", n);
  if (n == 1) {
    return;
  }
  if (n % 2 == 0) {
    return collatzConjecture(n / 2);
  } else {
    return collatzConjecture(3 * n + 1);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  collatzConjecture(n);
  return 0;
}