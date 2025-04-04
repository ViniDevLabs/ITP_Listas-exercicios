#include <stdio.h>
#include <string.h>

#define MAX_PREFIXOS 100
#define MAX_SUFIXOS 100
#define MAX_TAMANHO 100

int main() {

  // se utiliza uma matriz ao invés de um array para poder representar lista de strings, 
  // cada linha representa uma string e a coluna é o tamanho dela
  char prefixos[MAX_PREFIXOS][10];
  char sufixos[MAX_SUFIXOS][10];
  // n prefixos, m sufixos
  int n, m;

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%s", prefixos[i]);
  }

  scanf("%d", &m);

  for (int i = 0; i < m; i++) {
    scanf("%s", sufixos[i]);
  }

  char palavra[MAX_TAMANHO];

  while (1) {
    scanf("%s", palavra);

    if (strcmp(palavra, "-1") == 0) {
      break;
    }

    int tamanhoPalavra = strlen(palavra);
    int palavraFoiAlterada = 1;

    // Analisar prefixos
    for (int i = 0; i < n; i++) {
      int tamanhoPrefixo = strlen(prefixos[i]);
      if (tamanhoPalavra >= tamanhoPrefixo &&
          strncmp(palavra, prefixos[i], tamanhoPrefixo) == 0) {
        for (int j = 0; j < tamanhoPalavra - tamanhoPrefixo; j++) {
          palavra[j] = palavra[j + tamanhoPrefixo];
        }
        palavra[tamanhoPalavra - tamanhoPrefixo] = '\0';
        palavraFoiAlterada = 1;
        tamanhoPalavra -= tamanhoPrefixo;
      }
    }

    // Analisar sufixos
    for (int i = 0; i < m; i++) {
      int tamanhoSufixo = strlen(sufixos[i]);
      if (tamanhoPalavra >= tamanhoSufixo &&
          strcmp(palavra + tamanhoPalavra - tamanhoSufixo, sufixos[i]) == 0) {
        palavra[tamanhoPalavra - tamanhoSufixo] = '\0';
        palavraFoiAlterada = 1;
        tamanhoPalavra -= tamanhoSufixo;
      }
    }

    if (palavraFoiAlterada && tamanhoPalavra > 0) {
      printf("%s\n", palavra);
    }
  }

  return 0;
}