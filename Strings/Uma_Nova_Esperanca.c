#include <stdio.h>
#include <string.h>

const char S[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                  'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                  'U', 'V', 'W', 'X', 'Y', 'Z', '.', ',', '?', ' '};

int criptografar(char chaveK[5], char mensagem[200]) {
  int contador = 0;
  int temp;

  for (int i = 0; i < strlen(mensagem); i++) {

    // define o controle de percorrimento da chaveK
    if (contador == 4) {
      contador = 0;
    }
    // converte de char para int
    int avancar = chaveK[contador] - '0';
    contador += 1;

    // Descobre o índice do caractere da string no array S
    int encontrou = 0;
    for (int j = 0; j < 40; j++) {
      if (mensagem[i] == S[j]) {
        temp = j;
        encontrou = 1;
        break;
      }
    }
    if (!encontrou) {
      printf("Caractere invalido na entrada!");
      return 0;
    }

    // Define o índice de S do caractere que será inserido
    int novoIndice = (temp + avancar) % 40;

    // Define o novo valor do char na posição i
    mensagem[i] = S[novoIndice];
  }

  for (int i = 0; i < strlen(mensagem); i++) {
    printf("%c", mensagem[i]);
  }
  return 1;
}

int main() {

  char chaveK[5] = {0};
  char mensagem[200];

  // Lê a entrada do usuário e verifica se a chave K é válida
  scanf("%[^\n]", chaveK);
  getchar();
  if (chaveK[4] != '\0') {
    printf("Chave invalida!");
    return 0;
  }
  scanf("%[^\n]", mensagem);
  getchar();

  if (chaveK[4] != '\0') {
    printf("Chave invalida!");
    return 0;
  }

  if (!criptografar(chaveK, mensagem)) {
    return 0;
  }

  return 0;
}