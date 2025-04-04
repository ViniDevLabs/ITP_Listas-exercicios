#include <stdio.h>

int main() {
    int codigoCombo, valorPago;
    int valorCombo;
  
    scanf("%d %d", &codigoCombo, &valorPago);
    
    switch (codigoCombo) {
        case 1:
            valorCombo = 12;
            break;
        case 2:
            valorCombo = 23;
            break;
        case 3:
            valorCombo = 31;
            break;
        case 4:
            valorCombo = 28;
            break;
        case 5:
            valorCombo = 15;
            break;
        default:
            printf("Código de combo inválido.\n");
            return 1;
    }

    int troco = valorPago - valorCombo;

    if (troco > 0) {
        printf("Troco = %d reais", troco);
    } else if (troco == 0) {
        printf("Deu certim!");
    } else {
      // Para torná-lo positivo
        printf("Saldo insuficiente! Falta %d reais", -troco);
    }

    return 0;
}