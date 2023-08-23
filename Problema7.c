#include <stdio.h>

int main (){
    int n;
    
    printf("\tIngrese un valor cualquiera para saber su factorial.\n");
    scanf("%d", &n);

    if (n<0){
        printf("Los numeros negativos no son validos para encontrar un valor factorial.\n");
    } else{
        int factorial = n;

        for (int i = 1; i < n; ++i){
            factorial *= i;
        }
    printf("El factorial de %d es %d", n, factorial);
    }
    return 0;
}