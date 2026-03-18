#include <stdio.h>
#include <string.h>

int main() {
    char palabra[100];
    printf("ingrese una palabra: ");
    scanf("%s", palabra);

    int largo = strlen(palabra);
    printf("el largo de %s es de %d letras", palabra, largo);

    return 0;
}