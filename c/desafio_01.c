#include <stdio.h>
#define N 3

void lectura_matriz(int [][N], int);
void imprime_matriz(int [][N], int);
void imprime_matriz_2(int [][N], int);
void proceso(int [][N], int n, int *);
void resultado(int );

int main(){
    int matriz[3][3];
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

void proceso(int matriz[][N], int n, int *status){
    int st1, st2, st3;
    //st1 = suma_filas(...); // devuelve 0 falso 1 verdadero
    //st2 = suma_columnas(...); // devuelve 0 falso 1 verdadero
    //st3 = suma_diagonales(...); // devuelve 0 falso 1 verdadero
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