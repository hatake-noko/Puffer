#ifndef PUFFER_OBJ_H
#define PUFFER_OBJ_H

#include "line.h"
#include "literal.h"

typedef struct tag_obj_s{
    color_l color;
    line_s *line;
}obj_s;

#endif
