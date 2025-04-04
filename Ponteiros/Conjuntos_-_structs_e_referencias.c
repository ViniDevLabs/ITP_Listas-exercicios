#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int qtdElementos;
  int *elementos;
} Conjunto;

Conjunto *CriarConjunto() {
  Conjunto *conjunto = malloc(sizeof(Conjunto));
  conjunto->qtdElementos = 0;
  conjunto->elementos = calloc(0, sizeof(int));
  return conjunto;
}

void AumentarConjunto(Conjunto *conj) {
  conj->qtdElementos++;
  conj->elementos = realloc(conj->elementos, conj->qtdElementos * sizeof(int));
}

void uniao(Conjunto *conjA, Conjunto *conjB) {
  Conjunto *uniao = CriarConjunto();

  for (int i = 0; i < conjA->qtdElementos; i++) {
    AumentarConjunto(uniao);
    uniao->elementos[i] = conjA->elementos[i];
  }
  int qtdCasos = 0;
  for (int j = 0; j < conjB->qtdElementos; j++) {
    for (int n = 0; n < conjA->qtdElementos; n++) {
      if (conjB->elementos[j] == conjA->elementos[n]) {
        qtdCasos++;
      }
    }
    if (qtdCasos == 0) {
      AumentarConjunto(uniao);
      uniao->elementos[uniao->qtdElementos - 1] = conjB->elementos[j];
    } else {
      qtdCasos = 0;
      continue;
    }
  }
  printf("A união B == {");
  for (int k = 0; k < uniao->qtdElementos; k++) {
    if (k == uniao->qtdElementos - 1) {
      printf("%d", uniao->elementos[k]);
    } else
      printf("%d ", uniao->elementos[k]);
  }
  printf("}\n");
}

void intersecao(Conjunto *conjA, Conjunto *conjB) {
  Conjunto *intersecao = CriarConjunto();

  for (int i = 0; i < conjB->qtdElementos; i++) {
    for (int j = 0; j < conjA->qtdElementos; j++) {
      if (conjB->elementos[i] == conjA->elementos[j]) {
        AumentarConjunto(intersecao);
        intersecao->elementos[intersecao->qtdElementos - 1] = conjB->elementos[i];
      }
    }
  }
  printf("A interseção B == {");
  for (int k = 0; k < intersecao->qtdElementos; k++) {
    if (k == intersecao->qtdElementos - 1) {
      printf("%d", intersecao->elementos[k]);
    } else
      printf("%d ", intersecao->elementos[k]);
  }
  printf("}");
}

int main() {
  
  Conjunto *conjA = CriarConjunto();
  Conjunto *conjB = CriarConjunto();
  scanf("%d", &conjA->qtdElementos);
  conjA->elementos = realloc(conjA->elementos, conjA->qtdElementos * sizeof(int));
  
  for (int i = 0; i < conjA->qtdElementos; i++) {
    scanf("%d", &conjA->elementos[i]);
  }
  getchar();
  
  scanf("%d", &conjB->qtdElementos);
  conjB->elementos = realloc(conjB->elementos, conjB->qtdElementos * sizeof(int));
  
  for (int i = 0; i < conjB->qtdElementos; i++) {
    scanf("%d", &conjB->elementos[i]);
  }

  if (conjA->qtdElementos == 0) {
    if (conjB->qtdElementos == 0) {
      printf("A união B == {vazio}\nA interseção B == {vazio}");
      exit(1);
    } else {
      printf("A união B == {%d}\n", conjB->elementos[0]);
      printf("A interseção B == {vazio}");
      exit(1);
    }
  }

  uniao(conjA, conjB);
  intersecao(conjA, conjB);

  return 0;
}