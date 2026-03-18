#include <stdio.h>

#define N 7
#define INVALIDO 'O'   /* define casilla que no se puede ocupar */
#define VACIO ' '      /* define casilla que debe quedar vacia */
#define FICHA 'X'      /* define las casillas en las que se puede mover */

char tablero[N][N];

/* movimientos realizados */
int fila_origen[50], columna_origen[50];     
int filaFinal[50], columnaFinal[50];   
int total_movimientos = 0;               

int direccion_fila[4] = {-1, 1, 0, 0};
int direccion_columna[4] = {0, 0, -1, 1};

int contar_fichas() {  /*cuenta cuantas x hay en la matriz*/
    int contador = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (tablero[i][j] == FICHA)
                contador++;
    return contador;
}

void leer_tablero() {
    char fila[N + 2]; /* +2 para manejar '\n' y '\0' */
    for (int i = 0; i < N; i++) {
        if (scanf("%7[^\n]%*c", fila) != 1) { /* Leer 7 caracteres por fila */
            printf("Error leyendo la fila %d\n", i + 1);
            return;
        }
        for (int j = 0; j < N; j++)
            tablero[i][j] = fila[j];
    }
}


int resolver() { /*funcion que realiza el backtraking*/
    if (contar_fichas() == 1 && tablero[3][3] == FICHA)
        return 1;

    for (int fila = 0; fila < N; fila++) {
        for (int columna = 0; columna < N; columna++) {
            if (tablero[fila][columna] == FICHA) {
                for (int direccion = 0; direccion < 4; direccion++) {
                    int fila_media = fila + direccion_fila[direccion];
                    int columna_media = columna + direccion_columna[direccion];
                    int fila_destino = fila + 2 * direccion_fila[direccion];
                    int columna_destino = columna + 2 * direccion_columna[direccion];

                    if (fila_destino >= 0 && fila_destino < N && columna_destino >= 0 && columna_destino < N) {
                        
                        if (tablero[fila_media][columna_media] == FICHA &&
                            tablero[fila_destino][columna_destino] == VACIO &&
                            tablero[fila][columna] != INVALIDO &&
                            tablero[fila_media][columna_media] != INVALIDO &&
                            tablero[fila_destino][columna_destino] != INVALIDO) {

                            
                            tablero[fila][columna] = VACIO;
                            tablero[fila_media][columna_media] = VACIO;
                            tablero[fila_destino][columna_destino] = FICHA;

                            
                            fila_origen[total_movimientos] = fila;
                            columna_origen[total_movimientos] = columna;
                            filaFinal[total_movimientos] = fila_destino;
                            columnaFinal[total_movimientos] = columna_destino;
                            total_movimientos++;

                            
                            if (resolver())
                                return 1;

                            
                            total_movimientos--;
                            tablero[fila][columna] = FICHA;
                            tablero[fila_media][columna_media] = FICHA;
                            tablero[fila_destino][columna_destino] = VACIO;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

/*Imprime los movimientos realizados para encontrar la solucion*/
void imprimir_resultado() {
    if (resolver()) {
        printf("\nEn %d movimientos se encontro la solucion\n", total_movimientos);
        for (int i = 0; i < total_movimientos; i++)
            printf("%d: posicion <%d,%d> a <%d,%d>\n",
                   i + 1,
                   fila_origen[i] + 1, columna_origen[i] + 1,
                   filaFinal[i] + 1, columnaFinal[i] + 1);
    } else {
        printf("\nNo se encontro solucion\n");
    }
}

int main() {

    leer_tablero();
    imprimir_resultado();
    return 0;
}
