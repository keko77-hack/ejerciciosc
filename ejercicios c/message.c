/*
----------------------------------------------------------
Autor: [Tu Nombre]
Asignatura: Programación en C
Proyecto: Solitario de mesa "Continental"
Fecha: [Coloca la fecha]
----------------------------------------------------------
Descripción:
Resuelve el Solitario Continental (7x7) usando backtracking.
Lee la configuración inicial del tablero desde la entrada estándar.
----------------------------------------------------------
*/

#include <stdio.h>
#include <stdbool.h> 

#define N 7          // Dimensión del tablero (7x7)
#define INVALIDO -1  // Casillas fuera del tablero (zona 'O')
#define VACIO 0      // Casilla vacía
#define FICHA 1      // Casilla con ficha

//----------------------------------------------------------
// Estructura para almacenar un movimiento
//----------------------------------------------------------
typedef struct {
    int fr, fc;  // Fila y columna de origen (from)
    int tr, tc;  // Fila y columna de destino (to)
} Movimiento;

//----------------------------------------------------------
// Variables globales
//----------------------------------------------------------
int tablero[N][N];           // **Esta es la matriz 7x7 del juego.**
Movimiento movimientos[100]; 
int total_movimientos = 0;   

// Vectores de dirección (arriba, abajo, izquierda, derecha)
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

//----------------------------------------------------------
// Función: contar_fichas
// Devuelve la cantidad actual de fichas.
//----------------------------------------------------------
int contar_fichas() {
    int count = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (tablero[i][j] == FICHA)
                count++;
    return count;
}

//----------------------------------------------------------
// Función: leer_tablero
// Lee 7 líneas desde la entrada estándar para inicializar la matriz.
//----------------------------------------------------------
void leer_tablero() {
    char fila[N + 2]; 
    printf("Ingrese el tablero 7x7 (Use 'X' para valido y 'O' para invalido):\n");
    
    for (int i = 0; i < N; i++) {
        // Leemos 7 caracteres
        if (scanf("%7s", fila) != 1) {
            fprintf(stderr, "Error leyendo la fila %d\n", i + 1);
            return;
        }
        
        for (int j = 0; j < N; j++) {
            if (fila[j] == 'O') {
                tablero[i][j] = INVALIDO;
            } else if (fila[j] == 'X') {
                // Posición central (3,3 en base 0) se fuerza a VACIO
                if (i == 3 && j == 3) {
                    tablero[i][j] = VACIO;
                } else {
                    tablero[i][j] = FICHA;
                }
            } else {
                tablero[i][j] = INVALIDO; 
            }
        }
    }
}

//----------------------------------------------------------
// Función recursiva: resolver
// Implementación del backtracking.
//----------------------------------------------------------
bool resolver() {
    // Caso base de éxito
    if (contar_fichas() == 1 && tablero[3][3] == FICHA)
        return true;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (tablero[r][c] == FICHA) {
                for (int d = 0; d < 4; d++) {
                    int r1 = r + dr[d]; 
                    int c1 = c + dc[d];
                    int r2 = r + 2 * dr[d]; 
                    int c2 = c + 2 * dc[d];

                    // Verifica validez del salto
                    if (r2 >= 0 && r2 < N && c2 >= 0 && c2 < N && tablero[r2][c2] != INVALIDO &&
                        tablero[r1][c1] == FICHA &&
                        tablero[r2][c2] == VACIO) {

                        // Realizar movimiento
                        tablero[r][c] = VACIO;
                        tablero[r1][c1] = VACIO;
                        tablero[r2][c2] = FICHA;

                        movimientos[total_movimientos++] = (Movimiento){r, c, r2, c2};

                        if (resolver())
                            return true; 

                        // Deshacer movimiento (Backtrack)
                        total_movimientos--;
                        tablero[r][c] = FICHA;
                        tablero[r1][c1] = FICHA;
                        tablero[r2][c2] = VACIO;
                    }
                }
            }
        }
    }
    return false;
}

//----------------------------------------------------------
// Función: imprimir_resultado
// Muestra la secuencia de movimientos.
//----------------------------------------------------------
void imprimir_resultado() {
    if (resolver()) {
        printf("\nEn %d movimientos se encontro la solucion\n", total_movimientos);
        for (int i = 0; i < total_movimientos; i++) {
            printf("%d: posicion <%d,%d> a posicion <%d,%d>\n",
                       i + 1,
                       movimientos[i].fr + 1, movimientos[i].fc + 1,
                       movimientos[i].tr + 1, movimientos[i].tc + 1);
        }
    } else {
        printf("\nNo se encontro solucion\n");
    }
}

//----------------------------------------------------------
// Función principal
//----------------------------------------------------------
int main() {
    leer_tablero();     // Lee la matriz desde la entrada estándar
    imprimir_resultado(); 
    return 0;
}