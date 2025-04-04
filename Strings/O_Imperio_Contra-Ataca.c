#include <stdio.h>
#include <string.h>

char S[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                  'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                  'U', 'V', 'W', 'X', 'Y', 'Z', '.', ',', '?', ' '};

int obterIndice(char c) {
  for (int i = 0; i < strlen(S); i++) {
    if (c == S[i]) {
      return i;
      break;
    }
  }
  return 0;
}

void decodificarMensagem(char mensagemC[200], int chaveK[4]) {
  int j = 0;
  int tamanhoMensagem = strlen(mensagemC) - 1;
  for (int i = 0; i < tamanhoMensagem; i++) {
    if (j >= 4) {
      j = 0;
    }
    int chaveConvertida = chaveK[j];
    int novaPosicao = obterIndice(mensagemC[i]) - chaveConvertida;

    if (novaPosicao < 0) {
      novaPosicao = novaPosicao + strlen(S);
    }
    printf("%c", S[novaPosicao]);
    j++;
  }
}

void descobrirChave(char mensagemC[200], char fragmentoKp[]) {
  int chave[4];
  int counterCasos;
  int controlador = 0;

  for (int i = 0; i < strlen(mensagemC); i++) {
    controlador = 0;
    counterCasos = 0;
    for (int j = i; j < i + 4; j++) {
      int novaPosicao1 =
          obterIndice(mensagemC[j]) - obterIndice(fragmentoKp[controlador]);
      int novaPosicao2 = obterIndice(mensagemC[j + 4]) -
                         obterIndice(fragmentoKp[controlador + 4]);
      if (novaPosicao1 < 0) {
        novaPosicao1 = novaPosicao1 + strlen(S);
      }
      if (novaPosicao2 < 0) {
        novaPosicao2 = novaPosicao2 + strlen(S);
      }
      if (novaPosicao1 == novaPosicao2) {
        counterCasos++;
        chave[controlador] = novaPosicao1;
      }
      if (counterCasos >= 4) {
        if ((j + 1) % 4 != 0) {
          int resto = (j + 1) % 4;
          for (int i = 0; i < 2; i++) {
            int aux = chave[i + resto];
            chave[i + resto] = chave[i];
            chave[i] = aux;
          }
        }
        break;
      }
      controlador++;
    }
    if (counterCasos >= 4) {
      break;
    }
  }
  if (counterCasos >= 4) {
    for (int i = 0; i < 4; i++) {
      printf("%d", chave[i]);
    }
    printf("\n");
    decodificarMensagem(mensagemC, chave);
  } else {
    printf("Mensagem nao e da Resistencia!");
  }
}

int main(void) {
  char mensagemC[200];
  
  fgets(mensagemC, 200, stdin);
  
  char fragmento[] = "QUE A FORCA ESTEJA COM VOCE";
  
  descobrirChave(mensagemC, fragmento);
  
  return 0;
}