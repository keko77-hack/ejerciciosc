#include <stdio.h>
int main()
{
    //calculo de area de un rectangulo
    int l1 = 0;
    int l2 = 0;
    float arearec = 0;
    printf("ingresa el lado 1: ");
    scanf("%d", &l1);
    printf("ingresa el lado 2: ");
    scanf("%d", &l2);
    arearec = l1 * l2;
    printf("el area es: %f\n", arearec);

    //calculo d earea de un cubo
    int lc = 0;
    float areacub = 0;
    printf("ingresa la medicion del lado: ");
    scanf("%d", &lc);
    areacub = (lc * lc) * 6;
    printf("el aera del cubo es: %f\n", areacub);

    return 0;
    
}
