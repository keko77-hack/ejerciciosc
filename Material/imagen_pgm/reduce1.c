#include <stdio.h>
#include "fenster.h"
/*
Para compilar debe hacerlo de la siguiente manera:

En Linux
cc nombre_pgm.c -lX11 -lasound -o nombre_pgm && ./nombre_pgm
# macOS
cc nombre_pgm.c -framework Cocoa -framework AudioToolbox -o nombre_pgm && ./nombre_pgm
# windows
cc nombre_pgm.c -lgdi32 -lwinmm -o nombre_pgm.exe && nombre_pgm.exe
*/

int main(){
    FILE *ent, *sal;
    char magica[5];
    char comen[100];
    int ancho, alto, grises, pixel, i, j, i1, j1, cont = 0;
    unsigned int pixeles[800][800];
    unsigned int salida[800][800];
    for(i=0; i < 800; i++){
        for(j=0; j < 800; j++){
            salida[i][j] = 127;
        }
    }
    ent = fopen("Cartagena.pgm", "r");
    sal = fopen("Cartagena_chica.pgm", "w"); 
    fgets(magica, 5, ent);
    fprintf(sal, "%s", magica);
    fgets(comen, 100, ent);
    fprintf(sal, "%s", comen);

    fscanf(ent, "%d", &ancho);
    fscanf(ent, "%d", &alto);
    fscanf(ent, "%d", &grises);   
    fprintf(sal, "320 240\n%d\n", grises); 
    for (i = 0; i < alto; i++){
        for (j = 0; j < ancho; j++){
            fscanf(ent, "%d", &pixel);
            //fprintf(sal, "%d\n", pixel);
            pixeles[i][j] = pixel;
        }
    }
    i1 = 0;
    for (i = 0 ; i < alto; i++){
        if (i%2 != 0){
            j1 = 0;
            for(j = 0; j < ancho; j++)
                if (j%2 != 0){
                    salida[i1][j1] = pixeles[i][j];
                    j1++;
                }
            i1++;
        }
    }
           
    for (i = 0; i < 240; i++){
        for (j = 0; j < 320; j++){
            fprintf(sal, "%d\n", salida[i][j]);
        }
    }

/*
    uint32_t buf[ancho * alto];
    struct fenster f = { .title = "Mas clara", .width = ancho, .height = alto, .buf = buf };
    fenster_open(&f);
    while (fenster_loop(&f) == 0) {
        i = 0;
        while (i < alto){
            j = 0;
            while (j < ancho){
                //fenster_pixel(&f, j, i) = pixeles[i][j];
                fenster_pixel(&f, j, i) = pixeles[i][j];
                j++;
            }
            i++;
        }  
    }
    fenster_close(&f);
*/
    fclose(ent);
    fclose(sal);
    return 0;
}