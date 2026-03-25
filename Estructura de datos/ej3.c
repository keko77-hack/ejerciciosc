#include <stdio.h>

int maxproduc(int nums[], int n) {
    int numaxf = nums[0];
    int numact = nums[0];
    int minact = nums[0];

    for (int i = 1; i < n; i++) {
        if (nums[i] < 0) {
            int temp = numact;
            numact = minact;
            minact = temp;
        }

        int prodMax = numact * nums[i];
        if (nums[i] > prodMax) {
            numact = nums[i];
        } else {
            numact = prodMax;
        }

        int prodMin = minact * nums[i];
        if (nums[i] < prodMin) {
            minact = nums[i];
        } else {
            minact = prodMin;
        }

        if (numact > numaxf) {
            numaxf = numact;
        }
    }
    return numaxf;
}

int main() {
    int n;

    printf("Cantidad de elementos: ");
    if (scanf("%d", &n) != 1) return 1;

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Elemento [%d]: ", i);
        scanf("%d", &arr[i]);
    }

    int resultado = maxproduc(arr, n);

    printf("Resultado: %d\n", resultado);

    return 0;
}

