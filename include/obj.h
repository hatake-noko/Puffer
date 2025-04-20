#ifndef PUFFER_OBJ_H
#define PUFFER_OBJ_H

#include "line.h"
#include "literal.h"

typedef struct tag_obj_s{
    str_l name;
    color_l color;
    num_l line_size;
    line_s *line;
}obj_s;

#endif
