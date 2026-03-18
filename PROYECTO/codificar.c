/*Autores: Sergio Cifuentes y Ignacio Avila
  Seccion 4*/
  
#include <stdio.h>
#include <string.h>

void inicializa_alfabeto(char *alfabeto) {
    char arreglo[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' ','0','1','2','3','4','5','6','7','8','9','!',',','.',';',':','?','-','+','*','/'};
    int i;

    for (i = 0; i < 47; i++) { /*se crea un ciclo for que en cada vuelta se copia el caracter de arreglo en alfabeto*/
        alfabeto[i] = arreglo[i];
    }
    alfabeto[i] = '\0';
}

void lee_original(char *mensaje, int *N) {
    FILE *fichero;
    int i;

    fichero = fopen("original.txt", "r");
    if (fichero == NULL) {
        printf("no se pudo abrir original.txt\n");
        return;
    }

    fscanf(fichero, "%d#", N);    /*se almacena la clave en N y se usa fgets para leer el resto de la linea*/
    fgets(mensaje, 100, fichero);

    for (i = 0; mensaje[i] != '\0'; i++) {  /*se crea este for para eliminar el salto de linea (si es que se encuentra) y lo reemplaza por \0*/
        if (mensaje[i] == '\n') {
            mensaje[i] = '\0';
            break;
        }
    }
    fclose(fichero);
}

void primera_etapa(char *mensaje, char *resultado, char *alfabeto, int N) {
    int tam;
    int i, j;
    int posicion, nueva_pos;

    tam = strlen(alfabeto);

    for (i = 0; mensaje[i] != '\0'; i++) {  /*recorre cada caracter del mensaje*/
        posicion = -1;
        for (j = 0; alfabeto[j] != '\0'; j++) {  /*este for busca la letra dentro del mensaje y si la encuentra, se guarda la posicion*/
            if (alfabeto[j] == mensaje[i]) {
                posicion = j;
                break;
            }
        }
        if (posicion != -1) {
            nueva_pos = (posicion - N + tam) % tam;
            resultado[i] = alfabeto[nueva_pos];
        } else {
            resultado[i] = mensaje[i];
        }
    }
    resultado[i] = '\0';
}

void segunda_etapa(char *mensaje, char *resultado, char *alfabeto, int N) {
    int tam;
    int i, j;
    int posicion;

    tam = strlen(alfabeto);

    for (i = 0; mensaje[i] != '\0'; i++) {
        posicion = -1;
        for (j = 0; alfabeto[j] != '\0'; j++) {
            if (alfabeto[j] == mensaje[i]) {
                posicion = j;
                break;
            }
        }
        if (posicion != -1) {
            if (i % 3 == 0) {
                posicion = (posicion + N) % tam;
            }
            resultado[i] = alfabeto[posicion];
        } else {
            resultado[i] = mensaje[i];
        }
    }
    resultado[i] = '\0';
}

void codificar(char *mensaje, char *codificado, char *alfabeto, int N) {
    char etapa1[100];
    char etapa2[100];

    primera_etapa(mensaje, etapa1, alfabeto, N);
    segunda_etapa(etapa1, etapa2, alfabeto, N);

    sprintf(codificado, "%d#%s", N, etapa2); 
}

void graba_mensaje(char *mensaje) {
    FILE *fichero;
    fichero = fopen("codificado.txt", "w");
    if (fichero == NULL) {
        printf("no se pudo crear codificado.txt\n");
        return;
    }
    fprintf(fichero, "%s", mensaje);  /*se crea el archivo.txt en el cual se escribira el mensaje codificado*/
    fclose(fichero);
}

int main() {
    char original[100];
    char alfabeto[100];
    char codificado[100];
    int N;

    lee_original(original, &N);
    inicializa_alfabeto(alfabeto);
    codificar(original, codificado, alfabeto, N);
    graba_mensaje(codificado);

    return 0;
}