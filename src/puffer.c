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

void free_puffer(puffer_s *puffer){
    for(int i = 0; i < puffer->page_size; i ++){
        for(int j = 0; j < puffer->page[i].obj_size; j ++){
            free(puffer->page[i].obj[j].line);
        }
        free(puffer->page[i].obj);
    }
    free(puffer->page);
    return;
}
