#include <stdio.h>

void lectura_matriz(int [][3], int);
void muestra_matriz(int [][3], int);
void muestra_matriz2(int [][3], int);
//void proceso(...);
//void resultado(...);

int main(){
    // Declarar variables a utilizar
    int matriz[3][3];
    int filas, columnas;
    lectura_matriz(matriz, 3);
//    muestra_matriz(matriz, 3);
//    muestra_matriz2(matriz, 3);
    proceso(...);
    //resultado(...));
    return 0;
}

void lectura_matriz(int m[][3], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("Ingrese valor [%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

void muestra_matriz(int m[][3], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("Valor [%d][%d]: %d\n", i, j, m[i][j]);
        }
    }    
}

void muestra_matriz2(int m[][3], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%3d", m[i][j]);
        }
        printf("\n");
    }    
}
