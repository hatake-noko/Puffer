#include "literal.h"

#include <stdio.h>

void read_byte(byte_l *byte, FILE *file){
    fread(byte, sizeof(*byte), 1, file);
    return;
}
