#include <stdio.h>

int main() {
    float nota;
    float suma = 0;
    float notas[100];
    float promedio;
    float suma_cuadrados = 0;
    float desviacion = 0;
    int contador = 0;
    int not_max = 0;
    int not_min = 7;

    printf("ingrese una nota (0 para terminar): ");
    scanf("%f", &nota);

    while (nota != 0) { 
        if (nota >= 0 && nota <= 7) {
            printf("nota ingresada: %f\n", nota);
            notas[contador] = nota;
            suma = suma + nota;
            suma_cuadrados = suma_cuadrados + nota * nota;
            if (nota > not_max) not_max = nota;
            if (nota < not_min) not_min = nota;
            contador++;
        } else {
            printf("error: nota invalida\n");
        }
        printf("ingrese una nota (0 para terminar): ");
        scanf("%f", &nota);
    }

    if (contador == 0) {
        printf("no se ingresaron notas.\n");
    } else {
        promedio = suma / contador;
        desviacion = (suma_cuadrados / contador) - (promedio * promedio);

        printf("cantidad de notas validas: %d\n", contador);
        printf("promedio: %f\n", promedio);
        printf("nota mas alta: %d\n", not_max);
        printf("nota mas baja: %d\n", not_min);
        printf("desviacion estandar: %f\n", desviacion);
    }
    return 0;
}    