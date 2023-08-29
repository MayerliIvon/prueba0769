#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Jugador {
    char nombre[20];
    int puntuacion;
};

void jugarAdivinanzas(int *puntuacion) {
    printf("Vamos a jugar a las adivinanzas:)\n");
    printf("Responde:\n");

    char respuestas[5][20];
    const char *respuestasCorrectas[] = {"reloj", "platano", "girasol", "foco", "arcoiris"};
    
    printf("1. Tengo agujas y no se coser, tengo numeros y no se leer.\n");
    scanf("%s", &respuestas[0]);
    
    printf("2. Oro parece y plata no es, ¡y no lo adivinas de aqui a un mes!\n");
    scanf("%s", &respuestas[1]);
    
    printf("3. Es una planta con una flor, que gira y gira buscando el sol.\n");
    scanf("%s", &respuestas[2]);
    
    printf("4. Es pequeño como una pera, pero alumbra la casa entera.\n");
    scanf("%s", &respuestas[3]);
    
    printf("5. Cuando llueve y sale el sol, todos los colores los tengo yo.\n");
    scanf("%s", &respuestas[4]);

    for (int i = 0; i < 5; i++) {
        if (strcmp(respuestas[i], respuestasCorrectas[i]) == 0) {
            (*puntuacion)++;
        }
    }

    printf("Tu puntuacion: %d/5\n", *puntuacion);
}

void verHistorial(struct Jugador jugadores[], int numJugadores) {
    printf("Historial de jugadores:\n");
    for (int i = 0; i < numJugadores; i++) {
        printf("Nombre: %s | Puntuación: %d\n", jugadores[i].nombre, jugadores[i].puntuacion);
    }
}

void borrarHistorial() {
    FILE *archivo = fopen("adivinanzas.txt", "w"); 
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }
    
    fclose(archivo);
    printf("Historial de jugadores borrado.\n");
}

int main() {
    struct Jugador jugadores[10]; 
    int numJugadores = 0;

    int opcion;
    int puntuacion = 0;

    do {
        printf("\n-----------------------\n");
        printf("Seleccione una opcion:\n");
        printf("1. Jugar a las adivinanzas\n");
        printf("2. Ver historial de jugadores\n");
        printf("3. Borrar historial de jugadores\n");
        printf("4. Salir\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                puntuacion = 0;
                jugarAdivinanzas(&puntuacion);
                break;
            case 2:
                verHistorial(jugadores, numJugadores);
                break;
            case 3:
                borrarHistorial();
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción invalida.\n");
                break;
        }

        if (opcion == 1) {
            printf("Ingresa tu nombre: ");
            scanf("%s", jugadores[numJugadores].nombre);
            jugadores[numJugadores].puntuacion = puntuacion;
            numJugadores++;

            FILE *archivo = fopen("adivinanzas.txt", "a"); 
            if (archivo == NULL) {
                printf("No se pudo abrir el archivo.\n");
                return 1;
            }

            fprintf(archivo, "Nombre: %s | Puntuación: %d\n", jugadores[numJugadores - 1].nombre, jugadores[numJugadores - 1].puntuacion);
            fclose(archivo);
        }
    } while (opcion != 4);

    return 0;
}
