#ifndef PUFFER_LITERAL_H
#define PUFFER_LITERAL_H

#include <stdint.h>
#include <stdio.h>

typedef uint8_t byte_l;
typedef uint32_t num_l;
typedef uint8_t str_l[1024];
typedef uint16_t color_l;
typedef uint64_t pos_l;

void read_byte(byte_l *byte, FILE *file);

#endif
