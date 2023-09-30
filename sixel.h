#ifndef SIXEL_H
#define SIXEL_H

#include <stdlib.h>
#include <stdio.h>

#define ENTER_SIXEL "\eP9;0;q"
#define EXIT_SIXEL "\e\\"
#define SIXEL_NEWLINE "-"

char compile_sixel(_Bool bitfield[6]);

void print_big_px(size_t size, _Bool top_field[size], _Bool bottom_field[size]);

void enter_sixel_mode();

void exit_sixel_mode();

void sixel_newline();

#endif