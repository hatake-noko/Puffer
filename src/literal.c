#include "literal.h"

#include <stdio.h>

void read_byte(byte_l *byte, FILE *file){
    fread(byte, sizeof(*byte), 1, file);
    return;
}

void read_num(num_l *num, FILE *file){
    byte_l size;
    byte_l byte;
    num_l digit;

    fread(&size, sizeof(size), 1, file);
    digit = 0x100'00;
    for(int i = 1; i < size / 0x10 || i < 2; i ++){
        digit *= 0x100;
    }
    for(int i = 0; i < size / 0x10 || i < 2; i ++){
        fread(&byte, sizeof(byte), 1, file);
        *num += byte * digit;
        digit /= 0x100;
    }
    for(int i = 0; i < size % 0x10 || i < 2; i ++){
        fread(&byte, sizeof(byte), 1, file);
        *num += byte * digit;
        digit /= 0x100;
    }
    return;
}

void read_str(str_l str, FILE *file){
    for(int i = 0; i < 1023; i ++){
        fread(str, sizeof(str[i]), 1, file);
        if(str[i] == '\0'){
            break;
        }
    }
    str[1023] = '\0';
    return;
}

void read_color(color_l *color, FILE *file){
    byte_l mode;
    byte_l byte;

    fread(&mode, sizeof(mode), 1, file);
    *color = 0x00'00'00'00;
    switch(mode){
    case 0x00:
        fread(&byte, sizeof(byte), 1, file);
        *color += byte * 0x100'00'00;
    case 0x01:
        fread(&byte, sizeof(byte), 1, file);
        *color += byte * 0x100'00;
        fread(&byte, sizeof(byte), 1, file);
        *color += byte * 0x100;
        fread(&byte, sizeof(byte), 1, file);
        *color += byte * 0x1;
        break;
    case 0x10:
        *color = 0xffffff;
        break;
    case 0x11:
        *color = 0x000000;
        break;
    case 0x12:
        *color = 0xff3a2f;
        break;
    case 0x13:
        *color = 0x33c759;
        break;
    case 0x14:
        *color = 0x0061fd;
        break;
    case 0x15:
        *color = 0xffcc01;
        break;
    }
    return;
}
