#include <stdio.h>

int main() {
    float eurovalor = 166.386;
    float peseta = 0;
    float euro = 0;

    printf("ingrese la cantidad de pesetas: \n");
    scanf("%f", &peseta);

    euro = peseta / eurovalor;

    printf("es equivalente a: %f\n", euro);

    return 0;

}
