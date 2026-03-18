#include <stdio.h>

int main() {
    int nro1;
    int nro2;
    int suma;
    int multiplicacion;

    printf("ingrese el primer numero: \n");
    scanf("%d", &nro1);
    printf("ingrese el segundo numero: \n");
    scanf("%d", &nro2);

    suma = nro1 + nro2;
    multiplicacion = nro1 * nro2;

    printf("la suma es de: %d\n", suma);
    printf("la multiplicacion es de: %d", multiplicacion);

    return 0;
}
