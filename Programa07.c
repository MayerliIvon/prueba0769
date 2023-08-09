#include <stdio.h> //libreria para I/O 
#include <stdlib.h> //libreria para ejecutar instrucciones del SO

int main (){
    double num1, num2;
    system("clear");
    printf("Ingrese el primer número: ");
    if(scanf("%lf", &num1)!=1){
        printf("Error:Ingrese un número real válido.\n");
        return 1;
    }

    printf("Ingrese el segundo número: ");
    if (scanf("%lf", &num2)!=1){
        printf("Error: Ingrese un númer real válido.\n");
        return 1;
    }

    double suma = num1 + num2;
    double resta = num1-num2;
    double multiplicacion = num1*num2;
    if(num2==0){
        printf ("Error:No se puede dividir entre cero.\n");
        return 1;
    }
    
    double division = num1/num2;

    printf("\nResultados: \n");
    printf("Suma: %4lf\n", suma);
    printf("Resta: %4lf\n", resta);
    printf("Multiplicación: %4lf\n", multiplicacion);
    printf("División: %4lf\n", division);

    return 0;
}
