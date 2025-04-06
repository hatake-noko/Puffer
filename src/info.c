#include "info.h"

#include <string.h>
#include "proc.h"

void init_info(info_t *info){
    init_proc(&(info->tag));
    strcpy(info->title, "default title");
    strcpy(info->author, "default author");
    return;
}
