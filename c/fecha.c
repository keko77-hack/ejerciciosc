#include <stdio.h>

int main() {
    int mes = 0;
    int dia = 0;
    int anio = 0;

    printf("ingresa tu año: ");
    scanf("%d", &anio);

    printf("ingresa tu mes: ");
    scanf("%d", &mes);

    printf("ingresa tu dia: ");
    scanf("%d", &dia);
    
    if (mes == 2 && dia > 29) {
        printf("fecha invalida, ingrese otro valor de dia: ");
        scanf("%d", &dia);
        } else {
            if (mes == 1 || 3 || 5 || 7 || 8 || 10 || 12) {
                printf("ingresa un dia entre 1 y 31: ");
                scanf("%d", &dia);
                } else {
                    if (mes == 4 || 6 || 9 || 11) {
                        printf("ingresa tu dia entre 1 y 30: ");
                        scanf("%d", &dia);
                }
            }

        printf("la fecha es: %02d/%02d/%04d", dia, mes, anio);
    }
        return 0;

}

    

        


