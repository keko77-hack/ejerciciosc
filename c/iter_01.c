#include <stdio.h>

int main(){
    int v[100];
    int *p;
    v[0] = 100;
    v[1] = 200;
    p = v;
    p++;
    printf("%d\n", *p);
    printf("%p\n", v);
    printf("%p\n", p);
    //inicializar();
    //proceso();
    //mostrar();

    
    return 0;
}