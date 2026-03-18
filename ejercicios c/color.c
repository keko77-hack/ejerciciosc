#include <stdio.h>
#include <stdint.h>
#include "fenster.h"

/*
Compilación:
# Linux
cc color_pgm.c -lX11 -lasound -o color_pgm && ./color_pgm
# macOS
cc color_pgm.c -framework Cocoa -framework AudioToolbox -o color_pgm && ./color_pgm
# Windows (mingw)
cc color_pgm.c -lgdi32 -lwinmm -o color_pgm.exe && color_pgm.exe
*/

int main() {
    FILE *ent;
    char magica[5], comen[100];
    int ancho, alto, grises, pixel;
    unsigned int pixeles[800][800];

    // === 1. Leer imagen PGM ===
    ent = fopen("Cartagena.pgm", "r");
    if (!ent) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    fgets(magica, 5, ent);
    fgets(comen, 100, ent);
    fscanf(ent, "%d", &ancho);
    fscanf(ent, "%d", &alto);
    fscanf(ent, "%d", &grises);

    for (int i = 0; i < alto; i++) {
        for (int j = 0; j < ancho; j++) {
            fscanf(ent, "%d", &pixel);
            pixeles[i][j] = pixel;
        }
    }
    fclose(ent);

    // === 2. Crear ventana Fenster ===
    uint32_t buf[800 * 800];
    struct fenster f = {
        .title = "Imagen a Color",
        .width = ancho,
        .height = alto,
        .buf = buf
    };

    fenster_open(&f);

    // === 3. Mostrar con color ===
    while (fenster_loop(&f) == 0) {
        for (int i = 0; i < alto; i++) {
            for (int j = 0; j < ancho; j++) {
                int p = pixeles[i][j]; // intensidad (0-255)

                // --- Conversión de gris a color ---
                // Efecto color arcoíris según intensidad:
                int r = (p * 3) % 256;         // rojo crece rápido
                int g = (p * 2) % 256;         // verde más lento
                int b = (255 - p) % 256;       // azul inverso

                buf[i * ancho + j] = (r << 16) | (g << 8) | b;
            }
        }
    }

    fenster_close(&f);
    return 0;
}