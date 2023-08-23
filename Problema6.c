#include <stdio.h>

int main() {
    int inicial, final, i, cont = 0;
    
    printf("Ingrese el numero inicial: ");
    scanf("%d", &inicial);
    
    printf("Ingrese el numero final: ");
    scanf("%d", &final);
    
    for (int i = inicial; i <= final; i++) {
        if (i % 2 == 0) {
            cont++;
        }
    }
    
    printf("Hay %d numeros pares en el rango [%d, %d]\n", cont, inicial, final);
    
    return 0;
}