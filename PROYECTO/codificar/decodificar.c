/*Autores: Sergio Cifuentes y Ignacio Avila
  Seccion 4*/

#include <stdio.h>
#include <string.h>

void inicializa_alfabeto(char *alfabeto) { 
    char arreglo[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' ','0','1','2','3','4','5','6','7','8','9','!',',','.',';',':','?','-','+','*','/'};
    int i;

    for (i = 0; i < 47; i++) { 
        alfabeto[i] = arreglo[i];
    }
    alfabeto[i] = '\0';
}

void lee_codificado(char *mensaje, int *N) {
    FILE *fichero;
    int i;

    fichero = fopen("codificado.txt", "r");
    if (fichero == NULL) {
        printf("no se pudo abrir codificado.txt\n");
        return;
    }

    fscanf(fichero, "%d#", N);
    fgets(mensaje, 100, fichero);

    for (i = 0; mensaje[i] != '\0'; i++) { 
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
            if(i % 3 == 0) {
                posicion = (posicion - N + tam) % tam;
            }
            resultado[i] = alfabeto[posicion];
        } else {
            resultado[i] = mensaje[i];
        }
    }
    resultado[i] = '\0';
}

void segunda_etapa(char *mensaje, char *resultado, char *alfabeto, int N) {
    int tam;
    int i, j;
    int posicion, nueva_pos;

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
            nueva_pos = (posicion + N) % tam;
            resultado[i] = alfabeto[nueva_pos];
        } else {
            resultado[i] = mensaje[i];
        }
    }
    resultado[i] = '\0';
}

void decodificar(char *mensaje, char *decodificado, char *alfabeto, int N) {
    char etapa1[100];
    char etapa2[100];

    primera_etapa(mensaje, etapa1, alfabeto, N);
    segunda_etapa(etapa1, etapa2, alfabeto, N);

    strcpy(decodificado, etapa2);
}

void graba_mensaje_deco(char *mensaje) {
    FILE *fichero;
    fichero = fopen("decodificado.txt", "w");
    if (fichero == NULL) {
        printf("no se pudo crear decodificado.txt\n");
        return;
    }
    fprintf(fichero, "%s", mensaje);
    fclose(fichero);
}

int main() {
    char codificado[100];
    char alfabeto[100];
    char decodificado[100];
    int N;

    lee_codificado(codificado, &N);
    inicializa_alfabeto(alfabeto);
    decodificar(codificado, decodificado, alfabeto, N);
    graba_mensaje_deco(decodificado);

    return 0;
}