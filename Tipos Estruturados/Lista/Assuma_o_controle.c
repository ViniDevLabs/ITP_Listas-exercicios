#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char nome[30];
} Trabalhador;

typedef struct {
  int tamanho;
  Trabalhador** trabalhadores;
} ListaTrabalhadores;

ListaTrabalhadores* CriarLista() {
  ListaTrabalhadores* lista = malloc(sizeof(ListaTrabalhadores));
  lista -> tamanho = 0;
  lista -> trabalhadores = calloc(0, sizeof(Trabalhador*));
  return lista;
}

Trabalhador* CriarTrabalhador(char nome[30]) {
  Trabalhador* trabalhador = malloc(sizeof(Trabalhador));
  strcpy(trabalhador -> nome, nome);
  return trabalhador;
}

void AumentarLista(ListaTrabalhadores* lista) {
  lista -> tamanho++;
  lista -> trabalhadores = realloc(lista -> trabalhadores, lista -> tamanho * sizeof(Trabalhador*));
}

void DiminuirLista(ListaTrabalhadores* lista) {
  lista -> tamanho--;
  lista -> trabalhadores = realloc(lista -> trabalhadores, lista -> tamanho * sizeof(Trabalhador*));
}

int TrabalhadorJaExiste(ListaTrabalhadores* lista, char nome[30]) {
  for (int i = 0; i < lista->tamanho; i++) {
    if(strcmp(lista -> trabalhadores[i] -> nome, nome) == 0) {
      return i;
    }
  }
  return -1;
}

void AdicionarNaLista(ListaTrabalhadores* lista, char nome[30]){
  if(TrabalhadorJaExiste(lista,nome) == -1){
    AumentarLista(lista);
    lista -> trabalhadores[lista -> tamanho - 1] = CriarTrabalhador(nome);
  }
}

void TirarDaLista(ListaTrabalhadores* lista, char nome[30]){
  int index = TrabalhadorJaExiste(lista, nome);

  if (index != -1){

    for(int i = index; i < lista -> tamanho - 1; i++){
      lista -> trabalhadores[i] = lista -> trabalhadores[i + 1];
    }
    
    DiminuirLista(lista);
  }
}

void ListarTrabalhadores(ListaTrabalhadores* lista){
  printf("Atualmente trabalhando:\n");
  for(int i = 0; i < lista -> tamanho; i++){
    printf("%s\n", lista -> trabalhadores[i] -> nome);
  }
  printf("\n");
}

int main() {
  ListaTrabalhadores* lista = CriarLista();
  int nOperacoes;
  scanf("%d", &nOperacoes);

  for(int i = 0; i<nOperacoes; i++){
    getchar(); // Para pegar o \n no fim de cada scanf()

    char linha[40];
    scanf("%[^\n]", linha); // Lê todos os caracteres até o \n e deixa escapar

    char* operacao = strtok(linha, " "); // Separar em "INSERIR" ou "REMOVER" ou "IMPRIMIR" e o nome, caso exista

    if(strcmp(operacao, "INSERIR") == 0){
      char* nome = strtok(NULL, " ");
      AdicionarNaLista(lista, nome);
    } else if (strcmp(operacao, "REMOVER") == 0){
      char* nome = strtok(NULL, " ");
      TirarDaLista(lista, nome);
    } else if(strcmp(operacao, "IMPRIMIR") == 0){
      ListarTrabalhadores(lista);
    }
  }

  return 0;
}