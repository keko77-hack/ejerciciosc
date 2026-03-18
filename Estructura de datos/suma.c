#include <stdio.h>

int main () {
    int N;
    int suma = 0;
    printf("ingrese el valor de N: ");
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        if (i % 2 == 0) {
            suma = suma + i;
        
        }
        
    }
    printf("la suma es: %d", suma);
}