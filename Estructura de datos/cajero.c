#include <stdio.h>

int main() {
    int opcion = 0;
    float saldo;
    float monto;

    printf("Ingrese su saldo inicial: ");
    scanf("%f", &saldo);

    while (opcion != 4) {
        printf("\n1. Consultar saldo\n");
        printf("2. Depositar dinero\n");
        printf("3. Retirar dinero\n");
        printf("4. Salir\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            printf("Su saldo es: %.2f\n", saldo);
        }

        if (opcion == 2) {
            printf("Ingrese monto a depositar: ");
            scanf("%f", &monto);
            saldo = saldo + monto;
        }

        if (opcion == 3) {
            printf("Ingrese monto a retirar: ");
            scanf("%f", &monto);

            if (monto <= saldo) {
                saldo = saldo - monto;
            } else {
                printf("Saldo insuficiente\n");
            }
        }
    }

    return 0;
}