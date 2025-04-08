#include "puffer.h"

#include <string.h>
#include "info.h"

void init_puffer(puffer_t puffer){
    strcpy(puffer->path_dir, "(c:\\");
    strcpy(puffer->path_name, "untitled");
    init_info(&(puffer->info));
    return;
}
