#include <stdlib.h>
#include <stdio.h>

#include "sixel.h"

char compile_sixel(_Bool bitfield[6]) {
    int radix = 1;      //TODO find better name for vars
    char out_bucket = 63;

    for (int i = 0; i < 6; i++) {
        out_bucket += (bitfield[i] * radix);
        radix *= 2;
    }

    return out_bucket;
}

void print_big_px(size_t size, _Bool top_field[size], _Bool bottom_field[size]) {
    for (int i = 0; i < size; i++) {
        _Bool sixel_field[6];
        for (int j = 0; j < 6; j++) {
            sixel_field[j] = (j < 3) ? top_field[i] : bottom_field[i];
        }
        printf("!3%c", compile_sixel(sixel_field));
    }
}

void enter_sixel_mode() {
    printf(ENTER_SIXEL);
}
void exit_sixel_mode() {
    printf(EXIT_SIXEL);
}

void sixel_newline() {
    printf(SIXEL_NEWLINE);
}

void sixel_set_color(int register_id, int red, int green, int blue) {
    printf("#%d;2;%d;%d;%d", register_id, red, green, blue);
}