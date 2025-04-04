#include <stdio.h>
#include <string.h>

typedef struct {
  char nome[30];
  float preco;
  int qtd;
} Item;

int main() {
  float soma = 0;
  int qtdPessoas;

  while (1) {
    Item item;
    scanf("%s", item.nome);
    scanf("%fl", &item.preco);
    scanf("%i", &item.qtd);

    soma += (item.preco * item.qtd);

    int opcao;
    scanf("%d", &opcao);
    getchar();
    if (opcao != 1) {
      break;
    }
  }

  scanf("%d", &qtdPessoas);
  // Valor: R$ 120.00
  printf("Valor: R$ %.2f\n", soma);
  // Divisão R$ 24.00 para cada participante.
  printf("Divisão R$ %.2f para cada participante.", soma/qtdPessoas);

  return 0;
}