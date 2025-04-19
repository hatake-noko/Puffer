#include "set_info.h"

#include "set.h"

void init_set_info(set_info_s *set_info){
    init_set(&(set_info->set));
    ver = 0x00010000;
    author[0] = title[0] = 0x20;
    author[1] = title[1] = 0x00;
    return;
}
