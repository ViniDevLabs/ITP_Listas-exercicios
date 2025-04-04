#include <stdio.h>

int calc_mdc(int x, int y) {
  if (y == 0){
    return x;
  }
  return calc_mdc(y, x%y);
}

void calc_mdc_mmc(int x, int y, int *mdc, int *mmc) {
  *mdc = calc_mdc(x,y);
  *mmc = x*y / *mdc; 
}

int main() {
  int x, y;
  scanf("%d %d", &x, &y);

  int mdc, mmc;
  calc_mdc_mmc(x, y, &mdc, &mmc);
  printf("MDC = %d, MMC = %d", mdc, mmc);
  
  return 0;
}