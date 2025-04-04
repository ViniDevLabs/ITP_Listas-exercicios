#include <stdio.h>

int ehPar() {
  int num;

  scanf("%d", &num);

  if (num % 2 == 0) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  if (ehPar()) {
    printf("true");
  } else {
    printf("false");
  }
  return 0;
}