#include <stdio.h>

int main() {
    int contador = 0;

    for (int i = 100; i <= 200; i += 2) {
        printf("%d   ", i); // 3 espacios después del número
        contador++;

        if (contador % 6 == 0) {
            printf("\n"); // Salto de línea cada 6 números
        }
    }

    return 0;
}

