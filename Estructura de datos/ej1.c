#include <stdio.h>

int main() {
    int arr[] = {1,2,3,4,5,0,8};
    int n = 7; 

    int sumamayor = arr[0];
    int sumafinal = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > sumamayor + arr[i])
            sumamayor = arr[i];
        else
            sumamayor = sumamayor + arr[i];

        if (sumamayor > sumafinal)
            sumafinal = sumamayor;
    }

    printf("La suma maxima es: %d\n", sumafinal);

    return 0;
}