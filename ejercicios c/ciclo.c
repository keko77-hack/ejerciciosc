#include <stdio.h>

int main() {
    int numero[10];

    for (int i = 0; i < 10; i++) {
        printf("ingrese el numero %d: ", i + 1);
        scanf("%d", &numero[i]);
    }
    for (int i = 0; i < 10; i++) {
        if (numero[i] % 2 == 0) {
            printf("Numero ingresado: %d = par\n", numero[i]);
        }
        else {
            printf("Numero ingresado: %d = impar\n", numero[i]);
        }
    
    }
    return 0;
}
