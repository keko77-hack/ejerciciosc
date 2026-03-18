#include <stdio.h>

int main() {
    int numero;
    int suma = 0;
    int contador = 0;

    printf("Ingrese números para calcular el promedio (ingrese -999 para finalizar):\n");

    while (1) {
        scanf("%d", &numero);

        if (numero == -999) {
            break;
        }

        suma = suma + numero;
        contador++;
    }

    if (contador > 0) {
        float promedio = (float)suma / contador;
        printf("El promedio de los números ingresados es: %.2f\n", promedio);
    } else {
        printf("No se ingresaron números válidos.\n");
    }

    return 0;
}
