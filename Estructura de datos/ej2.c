#include <stdio.h>

int main () {
    int arr[] = {1 ,2 ,3 ,4 ,5};
    int n = 5;
    int k;
    int encontrado = 0;

    printf("Ingresa el valor de k:");
    scanf("%d", &k);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == k) {
                printf("La suma igual a %d encontrada en el arreglo es %d + %d \n", k, arr[i], arr[j]);
                encontrado = 1;
            }
        }

    }
    if (!encontrado) {
        printf("no existe par de numeros igual a k");

    }
}