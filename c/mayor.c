#include <stdio.h>

int main () {
    int a, b, c;

    printf("ingresa tres numeros enteros: \n");
    scanf("%d %d %d", &a, &b, &c);

    printf("el mayor es: %d\n", mayor(a, b, c));
    return 0;
}

int mayor(int nro1, int nro2, int nro3) {
    if (nro1 > nro2 && nro1 > nro3) {
        return nro1;
    } else if (nro2 > nro1 && nro2 > nro3) {
        return nro2;
    } else {
        return nro3;
    }
        
}
