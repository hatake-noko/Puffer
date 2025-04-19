#ifndef PUFFER_SET_INFO_H
#define PUFFER_SET_INFO_H

#include "set.h"
#include "literal.h"

typedef struct tag_set_info_s{
    set_s set;
    num_l ver;
    str_l author;
    str_l title;
}set_info_s;

#endif
