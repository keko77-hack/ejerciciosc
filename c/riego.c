#include <stdio.h>

/* Prototipos de funciones obligatorias (Regla 2) */
void mostrar_menu();
float calcular_tiempo(int plantas, float litros, float caudal);
void guardar_archivo(int plantas, float litros, float caudal, char nombre[]);

int main() {
    /* Variables locales (Regla 4: No variables globales) */
    int opcion = 0;
    float caudal = 0;
    char nombre_planta[50];
    int num_plantas = 0;
    float litros_req = 0;
    
    /* Variable para guardar el resultado del calculo */
    float minutos_resultado;

    /* Ciclo principal: se repite hasta que la opcion sea 5 */
    while (opcion != 5) {
        
        mostrar_menu(); /* Llamada a Funcion 1 */
        
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        /* Reemplazo del switch por if/else if */
        if (opcion == 1) {
            printf("Ingrese Caudal maximo (litros/min): ");
            scanf("%f", &caudal);
        }
        else if (opcion == 2) {
            printf("Ingrese Tipo de planta: ");
            scanf("%s", nombre_planta);
        }
        else if (opcion == 3) {
            printf("Ingrese Numero de plantas: ");
            scanf("%d", &num_plantas);
        }
        else if (opcion == 4) {
            printf("Ingrese Litros requeridos por planta: ");
            scanf("%f", &litros_req);
        }
        else if (opcion == 5) {
            /* Al salir, verificamos si tenemos datos para calcular */
            if (caudal > 0) {
                /* Llamada a Funcion 2: Calculo matematico */
                minutos_resultado = calcular_tiempo(num_plantas, litros_req, caudal);
                
                /* Llamada a Funcion 3: Generar reporte */
                guardar_archivo(num_plantas, litros_req, caudal, nombre_planta);
                
                printf("\nCalculo exitoso. Archivo 'riego.txt' generado.\n");
            } else {
                printf("\nAdvertencia: No se pudo calcular (Faltan datos o caudal es 0).\n");
            }
            printf("Saliendo del programa...\n");
        }
        else {
            /* Esto reemplaza al 'default' */
            printf("Opcion no valida. Intente de nuevo.\n");
        }
    }

    return 0;
}

/* * FUNCION 1: Mostrar Menu
 * Muestra las opciones solicitadas en la Pagina 2 del PDF
 */
void mostrar_menu() {
    printf("\n---------- MENU ----------\n");
    printf("1. Caudal maximo\n");
    printf("2. Tipo de planta o cultivo\n");
    printf("3. Numero de plantas\n");
    printf("4. Litros requeridos por planta\n");
    printf("5. Salir\n");
    printf("--------------------------\n");
}

/* * FUNCION 2: Calcular Tiempo
 * Aplica la formula: tiempo = (plantas * litros) / caudal
 */
float calcular_tiempo(int plantas, float litros, float caudal) {
    float resultado;
    resultado = (plantas * litros) / caudal;
    return resultado;
}

/* * FUNCION 3: Guardar Archivo
 * Escribe el archivo 'riego.txt' con el formato de la Pagina 3
 */
void guardar_archivo(int plantas, float litros, float caudal, char nombre[]) {
    FILE *archivo;
    float minutos, segundos, total_litros;

    /* Realizamos calculos para escribir en el reporte */
    total_litros = plantas * litros;
    minutos = (plantas * litros) / caudal;
    segundos = minutos * 60;

    /* Abrimos el archivo en modo escritura "w" */
    archivo = fopen("riego.txt", "w");

    if (archivo != NULL) {
        /* Escribimos linea por linea segun el formato visual del PDF */
        fprintf(archivo, "/*-------------------------------------*/\n");
        fprintf(archivo, "Sistema de riego por goteo\n");
        fprintf(archivo, "Plantas : %d\n", plantas);
        fprintf(archivo, "Litros por planta : %.0f\n", litros);
        fprintf(archivo, "Caudal valvula L/min : %.0f\n", caudal);
        fprintf(archivo, "-----------------------------------------\n");
        fprintf(archivo, "Tiempo de apertura : %.2f min\n", minutos);
        fprintf(archivo, "Tiempo en segundos : %.0f S\n", segundos);
        fprintf(archivo, "Litros totales : %.2f L\n", total_litros);
        fprintf(archivo, "/*--------------------------------------*/");
        
        fclose(archivo);
    }
}