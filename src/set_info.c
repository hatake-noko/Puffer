#include "set_info.h"

#include "set.h"

void init_set_info(set_info_s *set_info){
    init_set(&(set_info->set));
    set_info->ver = 0x00010000;
    set_info->author[0] = set_info->title[0] = 0x20;
    set_info->author[1] = set_info->title[1] = 0x00;
    return;
}
