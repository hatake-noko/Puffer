#ifndef PUFFER_PUFFER_H
#define PUFFER_PUFFER_H

#include "info.h"

typedef struct tag_puffer_t{
    char path_dir[256];
    char path_name[256];
 // process
    info_t info;
}puffer_t;

void init_puffer(puffer_t *puffer);

#endif
