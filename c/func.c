#include <stdio.h>
#include <string.h>
#include <ctype.h>


int contarconsonantes(char *cadena) {
    int consonantes = 0;
    char *p = cadena;
    while (*p != '\0') {
        if (*p == 'b' || *p == 'c' ||*p == 'd' || *p == 'f' ||*p == 'g' ||*p == 'h' ||*p == 'j' ||*p == 'k' ||*p == 'l' ||*p == 'm' ||*p == 'n' ||*p == 'p' ||*p == 'q' ||*p == 'r' ||*p == 's' ||*p == 't' ||*p == 'v' ||*p == 'w' ||*p == 'x' ||*p == 'y' ||*p == 'z') {
            consonantes = consonantes + 1;

        }
        p++;
    }
    return consonantes;
}

void mayusculas(char *cadena) {
    char *p = cadena;
    while (*p != '\0') {
        if (*p >= 'a' && *p <= 'z') {
            *p = *p - 32;
        }
        *p++;
    }
}

int iguales(char *cadena, char *cadena1) {
    return strcmp(cadena, cadena1) == 0;

}


int main() {
    char cadena[] = "sergio";
    char cadena1[] = "sergio";
    
    int consonantes = contarconsonantes(cadena);
    printf("hay %d consonantes\n", consonantes);

    printf("la cadena en mayuscula: \n");
    mayusculas(cadena);
    printf("%s\n", cadena);


    if (iguales(cadena, cadena1)) {
        printf("son iguales\n");
    } else {
        printf("no son iguales\n");

    }
}