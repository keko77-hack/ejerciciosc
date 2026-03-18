#include <stdio.h>

#define N 7

// --- Prototipos ---
void leer_tablero(char tablero[N][N]);
void imprimir_tablero(char tablero[N][N]);
int movimiento_valido(char tablero[N][N], int x1, int y1, int x2, int y2);
void mover(char tablero[N][N], int x1, int y1, int x2, int y2);
int contar_fichas(char tablero[N][N]);
void resolver(char tablero[N][N]);

int main() {
    char tablero[N][N];

    leer_tablero(tablero);

    printf("Tablero inicial:\n");
    imprimir_tablero(tablero);
    printf("\n");

    resolver(tablero);

    return 0;
}

// ----------------------------------------------------
// LEE la matriz 7x7 desde la entrada estándar (scanf)
// ----------------------------------------------------
void leer_tablero(char tablero[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf(" %c", &tablero[i][j]); // espacio ignora saltos de línea
        }
    }
}

// ----------------------------------------------------
// IMPRIME la matriz actual del tablero
// ----------------------------------------------------
void imprimir_tablero(char tablero[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c", tablero[i][j]);
        }
        printf("\n");
    }
}

// ----------------------------------------------------
// VERIFICA si un movimiento es válido según las reglas
// ----------------------------------------------------
int movimiento_valido(char t[N][N], int x1, int y1, int x2, int y2) {
    // Verificar que ambas posiciones estén dentro del tablero
    if (x1 < 0 || x1 >= N || y1 < 0 || y1 >= N ||
        x2 < 0 || x2 >= N || y2 < 0 || y2 >= N)
        return 0;

    // Evitar casillas no válidas ('O')
    if (t[x1][y1] == 'O' || t[x2][y2] == 'O')
        return 0;

    // La casilla origen debe tener ficha
    if (t[x1][y1] != 'X') return 0;

    // La casilla destino debe estar vacía
    if (t[x2][y2] != '0') return 0;

    // Movimiento horizontal
    if (x1 == x2 && (y2 == y1 + 2 || y2 == y1 - 2)) {
        int ym = (y1 + y2) / 2;
        return (t[x1][ym] == 'X');
    }

    // Movimiento vertical
    if (y1 == y2 && (x2 == x1 + 2 || x2 == x1 - 2)) {
        int xm = (x1 + x2) / 2;
        return (t[xm][y1] == 'X');
    }

    return 0; // no es válido
}

// ----------------------------------------------------
// EJECUTA el movimiento (actualiza el tablero)
// ----------------------------------------------------
void mover(char t[N][N], int x1, int y1, int x2, int y2) {
    int xm = (x1 + x2) / 2;
    int ym = (y1 + y2) / 2;
    t[x1][y1] = '0';  // origen vacío
    t[xm][ym] = '0';  // ficha saltada desaparece
    t[x2][y2] = 'X';  // destino recibe la ficha
}

// ----------------------------------------------------
// CUENTA cuántas fichas hay en el tablero
// ----------------------------------------------------
int contar_fichas(char t[N][N]) {
    int count = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (t[i][j] == 'X') count++;
    return count;
}

// ----------------------------------------------------
// PRUEBA movimientos válidos y los muestra
// ----------------------------------------------------
void resolver(char t[N][N]) {
    int movimientos = 0;

    // Mientras queden más de una ficha
    while (contar_fichas(t) > 1) {
        int encontrado = 0;

        for (int i = 0; i < N && !encontrado; i++) {
            for (int j = 0; j < N && !encontrado; j++) {
                if (t[i][j] != 'X') continue; // solo intentamos mover fichas

                int dx[4] = {0, 0, 2, -2};
                int dy[4] = {2, -2, 0, 0};

                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (movimiento_valido(t, i, j, ni, nj)) {
                        movimientos++;
                        printf("%d: posicion <%d,%d> a posicion <%d,%d>\n",
                               movimientos, i + 1, j + 1, ni + 1, nj + 1);
                        mover(t, i, j, ni, nj);
                        encontrado = 1;
                        break;
                    }
                }
            }
        }

        // Si no encontró ningún movimiento más, terminamos
        if (!encontrado)
            break;
    }

    printf("\nEn %d movimientos se encontró una secuencia válida (no necesariamente la óptima)\n", movimientos);
}
