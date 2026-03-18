#include <stdio.h>

int main() {
    int numero[5];
    int suma = 0;
    float promedio = 0;

    for (int i = 0; i < 5; i++) {
        printf("ingresa el numero %d: ", i + 1);
        scanf("%d", &numero[i]);
    }
    for (int i = 0; i < 5; i++) {
        suma = suma + numero[i];
    }


    promedio = suma / 5;
    
    printf("la suma es: %d\n", suma);
    printf("el promedio es: %.2f", promedio);

    return 0;

}
