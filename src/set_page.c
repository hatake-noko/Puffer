#include "set_page.h"

void init_set_page(set_page_s *set_page){
    init_set(&set_page->set);
    set_page->obj_size = 0;
    set_page->obj = NULL;
    return;
}
