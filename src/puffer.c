#include "puffer.h"

#include <stdlib.h>
#include "set_info.h"
#include "set_page.h"

void init_puffer(puffer_s *puffer){
    init_set_info(&(puffer->info));
    puffer->page_size = 1;
    puffer->page = (set_page_s *)malloc(sizeof(set_page_s) * 1);
    init_set_page(&(puffer->page[0]));
    return;
}
