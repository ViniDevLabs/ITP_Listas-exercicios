#include <stdio.h>

int main() {

  // O total de entradas será valorN * valorM

  int valorN, valorM;
  scanf("%d %d\n", &valorN, &valorM);

  double totalAgua = 0, totalDeserto = 0, totalVegetacao = 0, totalSemRecurso = 0,
      hostil = 0, total = valorN*valorM;

  char matriz[valorN][valorM];

  for (int i = 0; i < valorN; i++) {
    for (int j = 0; j < valorM; j++) {
      scanf(" %c", &matriz[i][j]);

      switch (matriz[i][j]) {
      case 'X':
        hostil = 1;
        break;

      case '~':
        totalAgua += 1;
        break;

      case '^':
        totalDeserto += 1;
        break;

      case '*':
        totalVegetacao += 1;
        break;

      case '.':
        totalSemRecurso += 1;
        break;
      }
    }
  }

  if (hostil) {
    printf("Planeta Hostil");
    return 0;
  } 

  if ((totalAgua/total) >= 0.5 && (totalAgua/total) < 0.85 && (totalVegetacao/total) >= 0.2){
    printf("Planeta Classe M");
  }

  else if ((totalAgua/total) >= 0.85){
    printf("Planeta Aquático");
  }

  else if ((totalDeserto/total) >= 0.6){
    printf("Planeta Desértico");
  }

  else if ((totalVegetacao/total) >= 0.65){
    printf("Planeta Selvagem");
  }

  else {
    printf("Planeta Inóspito");
  }

  return 0;
}