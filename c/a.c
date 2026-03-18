#include <stdio.h>

int promedio(int arreglo[], int tamaño) {
    int suma = 0;
    int i;
    for (i = 0; i < tamaño; i++) {
        suma += arreglo[i];
    }
    return suma;
}

int main() {
    int numeros[5];
    int i;

    for (i = 0; i < 5; i++) {
        printf("ingrese el numero %d: \n", i + 1);
        scanf("%d", &numeros[i]);
    }
    
    int resultado = promedio(numeros, 5);
    int prom = resultado / 5;
    printf("el promedio de los elementos es: %d", prom);

    return 0;

}
