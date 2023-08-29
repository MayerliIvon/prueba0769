#include <stdio.h>

int esPrimo(int num) {
    if (num <= 1) {
        return 0;
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

void mostrarHistorial() {
    FILE *archivo = fopen("numero.txt", "r"); 
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }
    
    printf("Historial de datos:\n");
    char linea[100];
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        printf("%s", linea);
    }
    
    fclose(archivo);
}

int main() {
    int opcion;
    
    do {
        printf("\n--------------------\n");
        printf("Seleccione una opcion:\n");
        printf("1. Ingresar numero\n");
        printf("2. Ver historial de datos\n");
        printf("3. Salir\n");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1: {
                int numero;
                printf("Ingrese un numero: ");
                scanf("%d", &numero);
                
                FILE *archivo = fopen("numero.txt", "a"); 
                if (archivo == NULL) {
                    printf("No se pudo abrir el archivo.\n");
                    return 1;
                }
                
                if (esPrimo(numero)) {
                    fprintf(archivo, "%d es un numero primo.\n", numero);
                    printf("%d es un numero primo.\n", numero);
                } else {
                    fprintf(archivo, "%d es un numero compuesto.\n", numero);
                    printf("%d es un numero compuesto.\n", numero);
                }
                
                fclose(archivo);
                break;
            }
            case 2:
                mostrarHistorial();
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida.\n");
                break;
        }
    } while (opcion != 3);
    
    return 0;
}


