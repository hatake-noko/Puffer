#ifndef PUFFER_PUFFER_H
#define PUFFER_PUFFER_H

#include "literal.h"
#include "set_info.h"
#include "set_page.h"

typedef struct tag_puffer_s{
    str_l path;
    set_info_s info;
    num_l page_size;
    set_page_s *page;
}puffer_s;

#endif
