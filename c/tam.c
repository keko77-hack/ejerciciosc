#include<stdio.h>

int main(){
    int a = 2;
    while (a >= 0 ){
        printf("%d\n", a);
        a = a * a;
    }
    return 0;
}