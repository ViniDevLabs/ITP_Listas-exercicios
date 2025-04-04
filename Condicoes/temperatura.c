#include <stdio.h>

int main() {
  float temperatura;
  char escala;

  scanf("%f", &temperatura);

  scanf(" %c", &escala);

  float temperaturaCelsius, temperaturaFarenheit, temperaturaKelvin;

  switch (escala) {
  case 'C':
  case 'c':
    temperaturaCelsius = temperatura;
    temperaturaFarenheit = temperatura * 1.8 + 32;
    temperaturaKelvin = temperatura + 273.15;
    break;

  case 'F':
  case 'f':
    temperaturaCelsius = (temperatura - 32) / 1.8;
    temperaturaFarenheit = temperatura;
    temperaturaKelvin = (temperatura - 32) / 1.8 + 273.15;
    break;

  case 'K':
  case 'k':
    temperaturaCelsius = temperatura - 273.15;
    temperaturaFarenheit = (temperatura - 273.15) * 1.8 + 32;
    temperaturaKelvin = temperatura;
    break;

  default:
    printf("Escala inválida.\n");
    return 1;
  }

  printf("Celsius: %.2f\n", temperaturaCelsius);
  printf("Farenheit: %.2f\n", temperaturaFarenheit);
  printf("Kelvin: %.2f\n", temperaturaKelvin);

  return 0;
}