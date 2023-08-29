#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Calificaciones {
    float valores[5];
};

void guardarHistorial(struct Calificaciones calificaciones) {
    FILE *archivo = fopen("calificaciones.txt", "a");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    fprintf(archivo, "Calificaciones: ");
    for (int i = 0; i < 5; i++) {
        fprintf(archivo, "%.2f ", calificaciones.valores[i]);
    }
    fprintf(archivo, "\n");
    fclose(archivo);
}

void verHistorial() {
    FILE *archivo = fopen("calificaciones.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    printf("Historial de analisis de calificaciones:\n");
    char linea[200];
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        printf("%s", linea);
    }

    fclose(archivo);
}

float calcMedia(struct Calificaciones calificaciones) {
    float suma = 0;
    for (int i = 0; i < 5; i++) {
        suma += calificaciones.valores[i];
    }
    return suma / 5;
}

float calcMediana(struct Calificaciones calificaciones) {
    for (int i = 0; i < 5 - 1; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (calificaciones.valores[i] > calificaciones.valores[j]) {
                float temp = calificaciones.valores[i];
                calificaciones.valores[i] = calificaciones.valores[j];
                calificaciones.valores[j] = temp;
            }
        }
    }
    return (calificaciones.valores[2] + calificaciones.valores[3]) / 2;
}

int calcModa(struct Calificaciones calificaciones) {
    int frecuenciaMax = 0;
    int moda = -1;

    for (int i = 0; i < 5; i++) {
        int frecuencia = 0;
        for (int j = 0; j < 5; j++) {
            if (calificaciones.valores[j] == calificaciones.valores[i]) {
                frecuencia++;
            }
        }

        if (frecuencia > frecuenciaMax) {
            frecuenciaMax = frecuencia;
            moda = calificaciones.valores[i];
        }
    }

    return moda;
}

float calcRango(struct Calificaciones calificaciones) {
    float max = calificaciones.valores[0];
    float min = calificaciones.valores[0];
    for (int i = 1; i < 5; i++) {
        if (calificaciones.valores[i] > max) {
            max = calificaciones.valores[i];
        }
        if (calificaciones.valores[i] < min) {
            min = calificaciones.valores[i];
        }
    }
    return max - min;
}

float calcDesviacionEstandar(struct Calificaciones calificaciones, float media) {
    float sumaDiferenciasCuadrado = 0;
    for (int i = 0; i < 5; i++) {
        sumaDiferenciasCuadrado += pow(calificaciones.valores[i] - media, 2);
    }
    return sqrt(sumaDiferenciasCuadrado / 5);
}

float calcVarianza(struct Calificaciones calificaciones, float media) {
    float sumaDiferenciasCuadrado = 0;
    for (int i = 0; i < 5; i++) {
        sumaDiferenciasCuadrado += pow(calificaciones.valores[i] - media, 2);
    }
    return sumaDiferenciasCuadrado / 5;
}

int main() {
    struct Calificaciones calificaciones;

    printf("Ingresa las 5 calificaciones:\n");
    for (int i = 0; i < 5; i++) {
        printf("Calificacion %d: ", i + 1);
        scanf("%f", &calificaciones.valores[i]);
    }

    float media = calcMedia(calificaciones);
    printf("Media: %.2f\n", media);

    float mediana = calcMediana(calificaciones);
    printf("Mediana: %.2f\n", mediana);

    int moda = calcModa(calificaciones);
    if (moda != -1) {
        printf("Moda: %d\n", moda);
    } else {
        printf("No hay moda en este conjunto de calificaciones.\n");
    }

    float rango = calcRango(calificaciones);
    printf("Rango: %.2f\n", rango);

    float desviacionEstandar = calcDesviacionEstandar(calificaciones, media);
    printf("Desviacion Estandar: %.2f\n", desviacionEstandar);

    float varianza = calcVarianza(calificaciones, media);
    printf("Varianza: %.2f\n", varianza);

    printf("\n¿Deseas ver el historial de analisis? (S/N): ");
    char opcion;
    scanf(" %c", &opcion);
    if (opcion == 'S' || opcion == 's') {
        verHistorial();
    }

    return 0;
}
