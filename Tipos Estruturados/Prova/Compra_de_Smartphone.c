#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char modelo[40];
  int memoria;
  float processador, camera, bateria;
} Smartphone;


int cadastraSmartphone(int qnt_cadastrada, Smartphone phones[]) {
  scanf("%[^\n]s", phones[qnt_cadastrada].modelo);
  getchar();

  scanf("%d", &phones[qnt_cadastrada].memoria);
  getchar();

  scanf("%f", &phones[qnt_cadastrada].processador);
  getchar();

  scanf("%f", &phones[qnt_cadastrada].camera);
  getchar();

  scanf("%f", &phones[qnt_cadastrada].bateria);
  getchar();

  qnt_cadastrada++;
  
  return qnt_cadastrada;
}

int pesquisaSmartphones(int qnt_cadastrada, Smartphone phones[], Smartphone reqMin) {
  int qtd = 0;
  for (int i = 0; i < qnt_cadastrada; i++) {
    if (phones[i].memoria >= reqMin.memoria && phones[i].processador >= reqMin.processador
      && phones[i].camera >= reqMin.camera && phones[i].bateria >= reqMin.bateria) {
      printf("Modelo: %s\n", phones[i].modelo);
      printf("Memoria: %iGB\n", phones[i].memoria);
      printf("Processador: %.2fGhz\n", phones[i].processador);
      printf("Camera: %.2fMPixels\n", phones[i].camera);
      printf("Bateria: %.2fmA\n\n", phones[i].bateria);
      qtd++;
      }
  }
  return qtd;
}

int main() {

  int qnt_cadastrada = 0;
  Smartphone phones[10];
  char continua;

  while(1){
    scanf("%c", &continua);
    getchar();

    if(continua == 'n'){
      break;
    }

    qnt_cadastrada = cadastraSmartphone(qnt_cadastrada, phones);
  }

  Smartphone phoneRef;

  scanf("%d", &phoneRef.memoria);
  getchar();

  scanf("%f", &phoneRef.processador);
  getchar();

  scanf("%f", &phoneRef.camera);
  getchar();

  scanf("%f", &phoneRef.bateria);
  getchar();

  int encontrados = pesquisaSmartphones(qnt_cadastrada, phones, phoneRef);
  printf("%d smartphones encontrados.", encontrados);
  return 0;
}