#ifndef PUFFER_LITERAL_H
#define PUFFER_LITERAL_H

#include <stdint.h>
#include <stdio.h>

typedef struct tag_num1_l{
    uint8_t content;
}num1_l;
typedef struct tag_num4_l{
    uint8_t content;
}num4_l;
typedef uint8_t str_l[1024];
typedef uint32_t color_l;
typedef uint64_t pos_l;

void read_num1(num1_l *num1, FILE *file);
void read_num4(num4_l *num4, FILE *file);
void read_str(str_l str, FILE *file);
void read_color(color_l *color, FILE *file);
void read_pos(pos_l *pos, FILE *file);

#endif
