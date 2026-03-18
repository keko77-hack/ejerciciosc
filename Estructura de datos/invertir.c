#include <stdio.h>

int main () {

    int N;
    int invertido = 0;
    int digito;

    printf("ingresa el numero a invertir: ");
    scanf("%d", &N);

    while (N > 0) {
        digito = N % 10;
        invertido = invertido * 10 + digito;
        N = N / 10;
    }
    printf("El numero invertido es: %d", invertido);

}