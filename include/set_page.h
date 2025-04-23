#ifndef PUFFER_SET_PAGE_H
#define PUFFER_SET_PAGE_H

#include "literal.h"
#include "obj.h"
#include "set.h"

typedef struct tag_set_page_s{
    set_s set;
    num_l obj_size;
    obj_s *obj;
}set_page_s;

void init_set_page(set_page_s *set_page);

#endif
