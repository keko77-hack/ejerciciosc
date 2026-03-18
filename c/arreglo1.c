#include <stdio.h>

int main() {
    int i;
    int arreglo1[5];
    int arreglo2[5];
    int suma[5];

    for (i = 0; i < 5; i++) {
        printf("ingresa el numero %d: ", i + 1);
        scanf("%d", &arreglo1[i]);
    }
    printf("ingresa los numeros para el arreglo 2 \n");    
    for (i = 0; i < 5; i++) {
        printf("ingresa el numero %d: ", i + 1);
        scanf("%d", &arreglo2[i]);
    }
    for (i = 0; i < 5; i++) {
        suma[i] = arreglo1[i] + arreglo2[i];

    printf("%d ", suma[i]);

    }
    

    return 0;

        
}

    