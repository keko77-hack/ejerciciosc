#include <stdio.h>

#define N 7
#define INVALIDO -1
#define VACIO 0
#define FICHA 1
#define MAX_MOV 100

// Tablero y movimientos
int tablero[N][N];
int mov_from_row[MAX_MOV], mov_from_col[MAX_MOV];
int mov_to_row[MAX_MOV], mov_to_col[MAX_MOV];
int total_movimientos = 0;

// Direcciones: arriba, abajo, izquierda, derecha
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

// Contar fichas actuales
int contar_fichas() {
    int count = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (tablero[i][j] == FICHA)
                count++;
    return count;
}

// Leer tablero desde entrada estándar (con o sin espacios)
void leer_tablero() {
    char c;
    printf("Ingrese el tablero 7x7 (X = ficha, O = invalido):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf(" %c", &c); // Espacio para ignorar saltos de línea y espacios
            if (c == 'O')
                tablero[i][j] = INVALIDO;
            else if (c == 'X')
                tablero[i][j] = (i == 3 && j == 3) ? VACIO : FICHA; // Casilla central vacía
            else
                tablero[i][j] = INVALIDO;
        }
    }

    // Imprimir tablero leído
    printf("\nTablero ingresado:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tablero[i][j] == INVALIDO) printf("O");
            else if (tablero[i][j] == VACIO) printf("V");
            else printf("X");
        }
        printf("\n");
    }
}

// Función recursiva para resolver
int resolver() {
    if (contar_fichas() == 1 && tablero[3][3] == FICHA)
        return 1; // Éxito

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (tablero[r][c] == FICHA) {
                for (int d = 0; d < 4; d++) {
                    int r1 = r + dr[d];
                    int c1 = c + dc[d];
                    int r2 = r + 2 * dr[d];
                    int c2 = c + 2 * dc[d];

                    if (r2 >= 0 && r2 < N && c2 >= 0 && c2 < N &&
                        tablero[r2][c2] != INVALIDO &&
                        tablero[r1][c1] == FICHA &&
                        tablero[r2][c2] == VACIO) {

                        // Realizar movimiento
                        tablero[r][c] = VACIO;
                        tablero[r1][c1] = VACIO;
                        tablero[r2][c2] = FICHA;

                        mov_from_row[total_movimientos] = r;
                        mov_from_col[total_movimientos] = c;
                        mov_to_row[total_movimientos] = r2;
                        mov_to_col[total_movimientos] = c2;
                        total_movimientos++;

                        if (resolver())
                            return 1; // Solución encontrada

                        // Deshacer movimiento (backtracking)
                        total_movimientos--;
                        tablero[r][c] = FICHA;
                        tablero[r1][c1] = FICHA;
                        tablero[r2][c2] = VACIO;
                    }
                }
            }
        }
    }
    return 0; // No se encontró solución
}

// Función principal
int main() {
    leer_tablero();          // Leer tablero
    if (resolver()) {        // Intentar resolver
        printf("\nEn %d movimientos se encontro la solucion\n", total_movimientos);
        for (int i = 0; i < total_movimientos; i++) {
            printf("%d: posicion <%d,%d> a posicion <%d,%d>\n",
                   i + 1,
                   mov_from_row[i] + 1, mov_from_col[i] + 1,
                   mov_to_row[i] + 1, mov_to_col[i] + 1);
        }
    } else {
        printf("\nNo se encontro solucion\n");
    }
    return 0;
}

