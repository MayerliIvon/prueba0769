#include <stdio.h>
#include <stdlib.h>

int lanzarDado() {
    return rand() % 6 + 1;
}

void guardarHistorial(int lanzamiento, int sumaDados, const char *resultado) {
    FILE *archivo = fopen("dados.txt", "a");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    fprintf(archivo, "Lanzamiento %d: Suma: %d - %s\n", lanzamiento, sumaDados, resultado);
    fclose(archivo);
}

void verHistorial() {
    FILE *archivo = fopen("dados.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    printf("Historial de juegos:\n");
    char linea[100];
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        printf("%s", linea);
    }

    fclose(archivo);
}

int main() {
    srand(1); //generador de números aleatorios 

    int sumaDados;
    int lanzamiento = 1;
    int ganaste = 0; 

    do {
        int dado1 = lanzarDado();
        int dado2 = lanzarDado();

        sumaDados = dado1 + dado2;

        printf("Lanzamiento %d: Dado 1: %d, Dado 2: %d, Suma: %d\n", lanzamiento, dado1, dado2, sumaDados);

        if (sumaDados == 8) {
            printf("¡Ganaste!\n");
            ganaste = 1;
            guardarHistorial(lanzamiento, sumaDados, "Ganaste");
            break;
        } else if (sumaDados == 7) {
            printf("¡Perdiste!\n");
            guardarHistorial(lanzamiento, sumaDados, "Perdiste");
            break;
        }

        lanzamiento++;
        guardarHistorial(lanzamiento, sumaDados, "Continua");
        printf("Enter para lanzar de nuevo...\n");
        getchar(); 
    } while (sumaDados != 8 && !ganaste); 

    if (!ganaste) {
        printf("¡Sigue intentándolo para obtener 8 o evitar 7!\n");
    }

    printf("\n¿Deseas ver el historial de juegos? (S/N): ");
    char opcion;
    scanf(" %c", &opcion);
    if (opcion == 'S' || opcion == 's') {
        verHistorial();
    }

    return 0;
}

