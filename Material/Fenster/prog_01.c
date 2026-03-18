// main.c
#include "fenster.h"
#define W 640
#define H 480
int main() {
  int numero;
  uint32_t buf[W * H];
  struct fenster f = { .title = "Chao", .width = W, .height = H, .buf = buf };
  fenster_open(&f);
  while (fenster_loop(&f) == 0) {
    for (int i = 0; i < W; i++) {
      for (int j = 0; j < H; j++) {
        //numero = rand();
        //printf("%d\n", numero);
        fenster_pixel(&f, i, j) = 0xffffff;
      }
    }
  }
  fenster_close(&f);
  return 0;
}

// cc prog_01.c -framework Cocoa -framework AudioToolbox -o prog_01.hac && ./prog_01.hac