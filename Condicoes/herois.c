#include <stdio.h>

int main() {
    int qtd, classe, ameaca;

    
    scanf("%d %d %d", &qtd, &classe, &ameaca);
    
    if (qtd == 0) {
        printf("Melhor chamar Saitama!\n");
    return 0;
    }
    
     if (classe == 5) {
        printf("Heróis vencerão!\n");
    return 0;
    }
    
    if (classe > ameaca) 
        printf("Heróis vencerão!\n");


    else if (classe == ameaca && qtd >= 3) 
        printf("Heróis vencerão!\n");
    
    else 
        printf("Melhor chamar Saitama!\n");
    
    
    return 0;
}