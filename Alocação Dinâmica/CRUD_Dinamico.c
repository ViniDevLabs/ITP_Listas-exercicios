#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nome[50];
  int idade;
  char sexo;
} Pessoa;

typedef struct {
  int tamanho;
  Pessoa **pessoas;
} ListaPessoas;

ListaPessoas *CriarLista() {
  ListaPessoas *lista = malloc(sizeof(ListaPessoas));
  lista->tamanho = 0;
  lista->pessoas = calloc(0, sizeof(Pessoa *));
  return lista;
}

Pessoa *Criar(char nome[50], int idade, char sexo) {
  Pessoa *pessoa = malloc(sizeof(Pessoa));
  strcpy(pessoa->nome, nome);
  pessoa->idade = idade;
  pessoa->sexo = sexo;
  return pessoa;
}

void AumentarLista(ListaPessoas *lista) {
  lista->tamanho++;
  lista->pessoas = realloc(lista->pessoas, lista->tamanho * sizeof(Pessoa *));
}

void DiminuirLista(ListaPessoas *lista) {
  lista->tamanho--;
  lista->pessoas = realloc(lista->pessoas, lista->tamanho * sizeof(Pessoa *));
}

int PessoaJaExiste(ListaPessoas *lista, char nome[50], int idade, char sexo) {
  for (int i = 0; i < lista->tamanho; i++) {
    if (strcmp(lista->pessoas[i]->nome, nome) == 0 &&
        lista->pessoas[i]->idade == idade && lista->pessoas[i]->sexo == sexo) {
      return i;
    }
  }
  return -1;
}

void Inserir(ListaPessoas *lista, char nome[50], int idade, char sexo) {
  if (PessoaJaExiste(lista, nome, idade, sexo) == -1) {
    AumentarLista(lista);
    lista->pessoas[lista->tamanho - 1] = Criar(nome, idade, sexo);
  }
}

void Deletar(ListaPessoas *lista, char nome[50], int idade, char sexo) {
  int index = PessoaJaExiste(lista, nome, idade, sexo);

  if (index != -1) {

    for (int i = index; i < lista->tamanho - 1; i++) {
      lista->pessoas[i] = lista->pessoas[i + 1];
    }

    DiminuirLista(lista);
  }
}

void Imprimir(ListaPessoas *lista) {
  for (int i = 0; i < lista->tamanho; i++) {
    printf("%s,%i,%c\n", lista->pessoas[i]->nome, lista->pessoas[i]->idade,
           lista->pessoas[i]->sexo);
  }
  printf("\n");
}

int main() {
  ListaPessoas *lista = CriarLista();

  while (1) {
    char operacao;
    scanf("%c", &operacao);
    getchar();

    if (operacao == 'p') {
      Imprimir(lista);
      break;
    }

    char nome[50];
    scanf("%[^\n]", nome);
    getchar();

    int idade;
    scanf("%d", &idade);
    getchar();

    char sexo;
    scanf("%c", &sexo);
    getchar();

    if (operacao == 'i') {
      Inserir(lista, nome, idade, sexo);
    }

    else if (operacao == 'd') {
      Deletar(lista, nome, idade, sexo);
    }
  }

  return 0;
}