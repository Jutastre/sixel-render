#include <stdlib.h>
#include <stdio.h>

#include "sixel.h"



void rotate(size_t size, _Bool (*array)[size]) {
    _Bool temp = (*array)[0];
    for (int i = 1; i < size; i++) {
        (*array)[i-1] = (*array)[i];
    }
    (*array)[size - 1] = temp;
}

int main(void) {
    _Bool test_field[] = { 0,0,1,0,1,1,1,1,1,1,0,0,1,0,1 };
    int test_field_size = (sizeof(test_field) / sizeof(test_field[0]));

    enter_sixel_mode();
    printf("!18%c", compile_sixel(test_field));
    exit_sixel_mode();
    printf("\n");

    _Bool test_field_reversed[test_field_size];
    for (int i = 0; i < test_field_size; i++) {
        test_field_reversed[i] = test_field[(test_field_size - 1) - i];
    }

    enter_sixel_mode();
    for (int i = 0; i < 50; i++) {
        print_big_px(test_field_size, test_field, test_field_reversed);
        print_big_px(test_field_size, test_field, test_field_reversed);
        print_big_px(test_field_size, test_field, test_field_reversed);
        sixel_newline();
        rotate(test_field_size, &test_field);
        rotate(test_field_size, &test_field_reversed);
    }
    exit_sixel_mode();
    printf("\n");

}