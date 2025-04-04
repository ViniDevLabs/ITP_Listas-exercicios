#include <stdio.h>

int main() {
  double tempoMin, tempoAtleta = 0;
  int numAtletas = 0, numSeries = 0;

  scanf("%lf", &tempoMin);

  while (tempoAtleta != -1) {
    scanf("%lf", &tempoAtleta);
    if (tempoAtleta <= tempoMin && tempoAtleta > 0) {
      numAtletas++;
    }
  }

  if (numAtletas > 0) {
    numSeries = 1;
    if (numAtletas > 8) {
      numSeries = (numAtletas + 8) / 8;
    }
  }

  printf("%d %d", numAtletas, numSeries);

  return 0;
}