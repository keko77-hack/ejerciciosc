#include <stdio.h>

#define N 7

// --- Variables Globales para Backtracking ---
int solucion_encontrada = 0; // 1 si encontramos la solución
int pasos_solucion[31][4];   // Almacena los pasos [mov_num][x1, y1, x2, y2]
int total_movimientos = 0;   // El número total de pasos en la solución

// --- Prototipos ---
void leer_tablero(char tablero[N][N]);
void imprimir_tablero(char tablero[N][N]);
int movimiento_valido(char t[N][N], int x1, int y1, int x2, int y2);
void mover(char t[N][N], int x1, int y1, int x2, int y2);
void deshacer_movimiento(char t[N][N], int x1, int y1, int x2, int y2);
int contar_fichas(char t[N][N]);
void resolver(char tablero[N][N], int mov_actual);

int main() {
    char tablero[N][N];

    // Lee el tablero desde la entrada
    leer_tablero(tablero);

    // Llama a la función recursiva para buscar la solución
    resolver(tablero, 0);

    // Si la solución fue encontrada, la imprime
    if (solucion_encontrada) {
        // Imprime el encabezado exacto del PDF 
        printf("En %d movimientos se encontro la solucion\n", total_movimientos);
        
        // Imprime cada paso
        for (int i = 0; i < total_movimientos; i++) {
            // Se suma 1 a las coordenadas para que sean 1-indexadas 
            printf("%d: posicion <%d,%d> a posicion <%d,%d>\n",
                   i + 1,
                   pasos_solucion[i][0] + 1, // Fila origen
                   pasos_solucion[i][1] + 1, // Col origen
                   pasos_solucion[i][2] + 1, // Fila destino
                   pasos_solucion[i][3] + 1  // Col destino
            );
        }
    } else {
        // En caso de que no haya solución (no debería pasar con la entrada dada)
        printf("No se encontro solucion.\n");
    }

    return 0;
}

// ----------------------------------------------------
// LEE la matriz 7x7 (incluyendo espacios y saltos de línea)
// ----------------------------------------------------
void leer_tablero(char tablero[N][N]) {
    int c; // Para limpiar el buffer
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // Leemos caracter por caracter, incluyendo el espacio
            scanf("%c", &tablero[i][j]); 
        }
        // Consumimos el caracter de salto de línea '\n' al final de cada fila
        while ((c = getchar()) != '\n' && c != EOF);
    }
}

// ----------------------------------------------------
// IMPRIME la matriz actual del tablero (para depuración)
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
// VERIFICA si un movimiento es válido (usando ' ' como vacío)
// ----------------------------------------------------
int movimiento_valido(char t[N][N], int x1, int y1, int x2, int y2) {
    // 1. Verificar límites del tablero
    if (x1 < 0 || x1 >= N || y1 < 0 || y1 >= N ||
        x2 < 0 || x2 >= N || y2 < 0 || y2 >= N)
        return 0;

    // 2. Evitar casillas no válidas ('O') [cite: 41]
    if (t[x1][y1] == 'O' || t[x2][y2] == 'O')
        return 0;

    // 3. La casilla origen debe tener una ficha ('X')
    if (t[x1][y1] != 'X') return 0;

    // 4. La casilla destino debe estar vacía (' ')
    if (t[x2][y2] != ' ') return 0; // CAMBIO: '0' por ' '

    // 5. Verificar horizontal
    if (x1 == x2 && (y2 == y1 + 2 || y2 == y1 - 2)) {
        int ym = (y1 + y2) / 2;
        return (t[x1][ym] == 'X'); // Debe saltar sobre una ficha
    }

    // 6. Verificar vertical
    if (y1 == y2 && (x2 == x1 + 2 || x2 == x1 - 2)) {
        int xm = (x1 + x2) / 2;
        return (t[xm][y1] == 'X'); // Debe saltar sobre una ficha
    }

    return 0; // No es un movimiento válido
}

// ----------------------------------------------------
// EJECUTA el movimiento (actualiza tablero)
// ----------------------------------------------------
void mover(char t[N][N], int x1, int y1, int x2, int y2) {
    int xm = (x1 + x2) / 2;
    int ym = (y1 + y2) / 2;
    t[x1][y1] = ' ';  // origen vacío
    t[xm][ym] = ' ';  // ficha saltada desaparece
    t[x2][y2] = 'X';  // destino recibe la ficha
}

// ----------------------------------------------------
// DESHACE el movimiento (para backtracking)
// ----------------------------------------------------
void deshacer_movimiento(char t[N][N], int x1, int y1, int x2, int y2) {
    int xm = (x1 + x2) / 2;
    int ym = (y1 + y2) / 2;
    t[x1][y1] = 'X';  // origen recupera la ficha
    t[xm][ym] = 'X';  // ficha saltada reaparece
    t[x2][y2] = ' ';  // destino se vacía
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
// FUNCIÓN RECURSIVA (BACKTRACKING)
// ----------------------------------------------------
void resolver(char t[N][N], int mov_actual) {
    // Si ya encontramos una solución, no seguimos buscando
    if (solucion_encontrada) return;

    // Condición de Victoria: 1 ficha y está en el centro [cite: 40]
    if (contar_fichas(t) == 1) {
        if (t[N/2][N/2] == 'X') { // N/2 es 3 (la central 3,3)
            solucion_encontrada = 1;
            total_movimientos = mov_actual;
        }
        return;
    }

    // --- Parte Recursiva ---
    // Intentar todos los movimientos posibles desde el estado actual
    for (int i = 0; i < N; i++) {       // Fila origen
        for (int j = 0; j < N; j++) {   // Col origen
            if (t[i][j] == 'X') { // Si hay una ficha para mover
                
                // Intentar los 4 posibles saltos (arriba, abajo, izq, der)
                int dx[] = {0, 0, 2, -2};
                int dy[] = {2, -2, 0, 0};

                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k]; // Fila destino
                    int nj = j + dy[k]; // Col destino

                    if (movimiento_valido(t, i, j, ni, nj)) {
                        
                        // 1. Hacer el movimiento
                        mover(t, i, j, ni, nj);

                        // 2. Guardar el paso (en 0-indexing)
                        pasos_solucion[mov_actual][0] = i;
                        pasos_solucion[mov_actual][1] = j;
                        pasos_solucion[mov_actual][2] = ni;
                        pasos_solucion[mov_actual][3] = nj;

                        // 3. Llamada recursiva (probar el siguiente movimiento)
                        resolver(t, mov_actual + 1);

                        // Si la llamada recursiva encontró la solución, paramos
                        if (solucion_encontrada) return;

                        // 4. Deshacer el movimiento (Backtrack)
                        // Si llegamos aquí, fue un callejón sin salida
                        deshacer_movimiento(t, i, j, ni, nj);
                    }
                }
            }
        }
    }
}
