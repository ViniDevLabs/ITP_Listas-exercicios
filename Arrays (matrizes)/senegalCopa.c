#include <stdio.h>

int calcular_aposta(int largura, int altura, int bandeira[altura][largura], char cor) {
  int soma = 0;

  if (cor == 'G'){
    for (int i = 0; i<altura; i++){
      for (int j = 0; j+1 <= largura/3; j++){
        soma += bandeira[i][j];
      }
    }
  }
  else if (cor == 'Y'){
    for (int i = 0; i<altura; i++){
      for (int j = (largura/3); j < 2*largura/3; j++){
        soma += bandeira[i][j];
      }
    }
  }
  else if (cor == 'R'){
    for (int i = 0; i<altura; i++){
      for (int j = 2*largura/3; j < largura; j++){
        soma += bandeira[i][j];
      }
    }
  }
  
  return soma;
}

int main() {
  int altura = 0, largura = 0, valorInicial = 0;
  char cor;
  scanf("%d %d %c", &largura, &valorInicial, &cor);

  altura = (largura * 2) / 3;

  int bandeira[altura][largura];
  for (int i = 0; i < altura; i++) {
    int valor = valorInicial;
    for (int j = 0; j < largura; j++) {
      if (j % (altura / 2) == 0) {
        valor++;
      }
      bandeira[i][j] = valor;
    }
  }

  printf("%d", calcular_aposta(largura, altura, bandeira, cor));

  return 0;
}