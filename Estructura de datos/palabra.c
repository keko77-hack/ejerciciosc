#include <stdio.h>
#include <string.h>

int main () {

    char palabra[100];
    int contador = 0;

    printf("ingrese su palabra: ");
    scanf("%c", palabra);

    for (int i = 0; i < strlen(palabra); i++) {
        char letra = palabra[i];

        if (letra == "a" || letra == "e" || letra == "i" || letra == "o" || letra == "u") {
            contador++;
        } 
    }
    printf("la cantidad de vocales son: %d", contador);
}