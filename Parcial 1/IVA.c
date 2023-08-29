#include <stdio.h>

void guardarDatos(float precio, float precioSinIVA, float iva) {
    FILE *archivo = fopen("salida.txt", "a"); 
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }
    
    fprintf(archivo, "Precio: %.2f quetzales | Precio sin IVA: %.2f quetzales | IVA: %.2f quetzales\n", precio, precioSinIVA, iva);
    fclose(archivo);
}

void mostrarHistorial() {
    FILE *archivo = fopen("salida.txt", "r"); 
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
        printf("\n----------------------\n");
        printf("Seleccione una opcion:\n");
        printf("1. Calcular IVA y precio sin IVA\n");
        printf("2. Ver historial de datos\n");
        printf("3. Salir\n");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1: {
                float precio;
                printf("Ingrese el precio en quetzales: ");
                scanf("%f", &precio);
                
                float iva = precio * 0.12;
                float precioSinIVA = precio - iva;
                
                printf("Precio sin IVA: %.2f quetzales\n", precioSinIVA);
                printf("IVA (12%%): %.2f quetzales\n", iva);
                
                guardarDatos(precio, precioSinIVA, iva);
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

    