#include <stdio.h>
#include <string.h>

int main() {
    char palabra[100];
    char palabra1[100];
    printf("ingrese una palabra: ");
    scanf("%s", palabra);

    printf("ingrese otra palagra: ");
    scanf("%s", palabra1);

    int mayor = strcmp(palabra, palabra1);

    if (mayor == 0) {
        printf("las palabras son iguales");
    } else if (mayor < 0) {
        printf("%s es mayor que %s", palabra1, palabra);
    } else {
        printf("%s es mayor que %s", palabra, palabra1);

    }
    return 0;
}