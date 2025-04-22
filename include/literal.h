#ifndef PUFFER_LITERAL_H
#define PUFFER_LITERAL_H

#include <stdint.h>
#include <stdio.h>

typedef uint8_t byte_l;
typedef uint32_t num_l;
typedef uint8_t str_l[1024];
typedef uint32_t color_l;
typedef uint64_t pos_l;

void read_byte(byte_l *byte, FILE *file);
void read_num(num_l *num, FILE *file);
void read_str(str_l str, FILE *file);
void read_color(color_l *color, FILE *file);
void read_pos(pos_l *pos, FILE *file);

#endif
