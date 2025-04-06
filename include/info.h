#ifndef PUFFER_INFO_H
#define PUFFER_INFO_H

#include "proc.h"

typedef struct tag_info_t{
    proc_t tag;
    char title[256];
    char author[256];
}info_t;

void init_info(info_t info);

#endif
