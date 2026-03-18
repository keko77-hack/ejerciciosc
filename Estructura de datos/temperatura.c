#include <stdio.h>

int main() {
    float temp[7];
    float suma = 0;
    float mayor, menor, promedio;
    int i;
    int contador = 0;

    for (i = 0; i < 7; i++) {
        printf("Ingrese temperatura: ");
        scanf("%f", &temp[i]);
        suma = suma + temp[i];
    }

    mayor = temp[0];
    menor = temp[0];

    for (i = 1; i < 7; i++) {
        if (temp[i] > mayor) {
            mayor = temp[i];
        }

        if (temp[i] < menor) {
            menor = temp[i];
        }
    }

    promedio = suma / 7;

    for (i = 0; i < 7; i++) {
        if (temp[i] > promedio) {
            contador++;
        }
    }

    printf("Mayor: %.2f\n", mayor);
    printf("Menor: %.2f\n", menor);
    printf("Promedio: %.2f\n", promedio);
    printf("Dias sobre promedio: %d\n", contador);

    return 0;
}