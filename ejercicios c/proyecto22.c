#include <stdio.h>

#define N 7
#define INVALIDO '0'   /* Casilla no valida */
#define VACIO ' '      /* Casilla vacia (solo el centro) */
#define FICHA 'X'      /* Casilla con ficha */

/* Tablero del juego */
char tablero[N][N];

/* Movimientos realizados */
int fila_origen[50], col_origen[50];     /* Origen del movimiento */
int fila_destino[50], col_destino[50];   /* Destino del movimiento */
int total_movimientos = 0;               /* Contador de movimientos realizados */

/* Direcciones para mover fichas: arriba, abajo, izquierda, derecha */
int delta_fila[4] = {-1, 1, 0, 0};
int delta_columna[4] = {0, 0, -1, 1};

/* ---------------------------------------------------------
   Contar cuantas fichas quedan en el tablero
--------------------------------------------------------- */
int contar_fichas() {
    int count = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (tablero[i][j] == FICHA)
                count++;
    return count;
}

/* ---------------------------------------------------------
   Leer tablero desde entrada estandar
--------------------------------------------------------- */
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

/* ---------------------------------------------------------
   Resolver el juego usando backtracking
--------------------------------------------------------- */
int resolver() {
    /* Caso base: si queda solo una ficha en el centro */
    if (contar_fichas() == 1 && tablero[3][3] == FICHA)
        return 1;

    /* Buscar todas las fichas en el tablero */
    for (int fila = 0; fila < N; fila++) {
        for (int col = 0; col < N; col++) {
            if (tablero[fila][col] == FICHA) {
                /* Intentar mover en las 4 direcciones */
                for (int dir = 0; dir < 4; dir++) {
                    int fila_intermedia = fila + delta_fila[dir];
                    int col_intermedia = col + delta_columna[dir];
                    int fila_dest = fila + 2 * delta_fila[dir];
                    int col_dest = col + 2 * delta_columna[dir];

                    /* Verificar limites del tablero */
                    if (fila_dest >= 0 && fila_dest < N && col_dest >= 0 && col_dest < N) {
                        /* Verificar que el movimiento sea valido */
                        if (tablero[fila_intermedia][col_intermedia] == FICHA &&
                            tablero[fila_dest][col_dest] == VACIO &&
                            tablero[fila][col] != INVALIDO &&
                            tablero[fila_intermedia][col_intermedia] != INVALIDO &&
                            tablero[fila_dest][col_dest] != INVALIDO) {

                            /* Realizar el movimiento */
                            tablero[fila][col] = VACIO;
                            tablero[fila_intermedia][col_intermedia] = VACIO;
                            tablero[fila_dest][col_dest] = FICHA;

                            /* Guardar movimiento */
                            fila_origen[total_movimientos] = fila;
                            col_origen[total_movimientos] = col;
                            fila_destino[total_movimientos] = fila_dest;
                            col_destino[total_movimientos] = col_dest;
                            total_movimientos++;

                            /* Llamada recursiva */
                            if (resolver())
                                return 1;

                            /* Backtracking: deshacer movimiento */
                            total_movimientos--;
                            tablero[fila][col] = FICHA;
                            tablero[fila_intermedia][col_intermedia] = FICHA;
                            tablero[fila_dest][col_dest] = VACIO;
                        }
                    }
                }
            }
        }
    }
    return 0; /* No se encontro solucion */
}

/* ---------------------------------------------------------
   Imprimir movimientos realizados
--------------------------------------------------------- */
void imprimir_resultado() {
    if (resolver()) {
        printf("\nSe encontro solucion en %d movimientos:\n", total_movimientos);
        for (int i = 0; i < total_movimientos; i++)
            printf("%d: de <%d,%d> a <%d,%d>\n",
                   i + 1,
                   fila_origen[i] + 1, col_origen[i] + 1,
                   fila_destino[i] + 1, col_destino[i] + 1);
    } else {
        printf("\nNo se encontro solucion\n");
    }
}

/* ---------------------------------------------------------
   Funcion principal
--------------------------------------------------------- */
int main() {
    
    leer_tablero();
    imprimir_resultado();
    return 0;
}
