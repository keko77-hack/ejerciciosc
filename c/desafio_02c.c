#include <stdio.h>
#define N 3

void lectura_matriz(int [][N], int);
void imprime_matriz(int [][N], int);
void imprime_matriz_2(int [][N], int);
void proceso(int [][N], int n, int *);
int suma_filas(int [][N], int );
int suma_columnas(int [][N], int );
int suma_diagonales(int [][N], int );
void resultado(int );

int main(){
    int matriz[N][N];
    int status;
    lectura_matriz(matriz, N);
    void imprime_matriz(int [][N], int);
    void imprime_matriz_2(int [][N], int);
    proceso(matriz, N, &status);
    resultado(status);
    return 0;
}

void lectura_matriz(int m[][N], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("Numero: ");
            scanf("%d", &m[i][j]);
        }
    }
}

void imprime_matriz(int m[][N], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("M[%d][%d]: %d\n", i, j, m[i][j]);
        }
    }
}

void imprime_matriz_2(int m[][N], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%3d ",m[i][j]);
        }
        printf("\n");
    }
}

void proceso(int m[][N], int n, int *status){
    int st1, st2, st3;
    st1 = suma_filas(m, n); // devuelve 0 falso 1 verdadero
    st2 = suma_columnas(m, n); // devuelve 0 falso 1 verdadero
    st3 = suma_diagonales(m, n); // devuelve 0 falso 1 verdadero
    if ((st1 + st2 + st3)!=3){
        *status = 0;
    }
    else{
        *status = 1;
    }
}

void resultado(int status ){
    if (status == 0){
        printf("No es un cuadrado magico\n");
    }
    else{
        printf("Es un un cuadrado magico\n");
    }
}

int suma_filas(int m[][N], int n){
    int status = 1; // Supongo que es verdadero
    int suma_1, suma_2;
    suma_1 = m[0][0] + m[0][1] + m[0][2];
    for (int i = 0; i < n; i++){
        suma_2 = 0;
        for (int j = 0; j < n; j++){
            suma_2 = suma_2 + m[i][j];
        }
        if (suma_1 != suma_2){
            status = 0;
        }
    }
    return status;
}

int suma_columnas(int m[][N], int n){
    int status = 1; // Supongo que es verdadero
    int suma_1, suma_2;
    suma_1 = m[0][0] + m[1][0] + m[2][0];
    for (int i = 0; i < n; i++){
        suma_2 = 0;
        for (int j = 0; j < n; j++){
            suma_2 = suma_2 + m[j][i];
        }
        if (suma_1 != suma_2){
            status = 0;
        }
    }
    return status;
}

int suma_diagonales(int m[][N], int n){
    int status = 1; // Supongo que es verdadero
    int suma_1, suma_2;
    suma_1 = m[0][0] + m[1][1] + m[2][2];
    suma_2 = m[2][0] + m[1][1] + m[0][2];
    if (suma_1 != suma_2){
        status = 0;
    }
    return status;
}