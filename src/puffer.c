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

#define ORDER_SIZE 2

void read_puffer(puffer_s *puffer){
    FILE *pfr_file;
    byte_l order[ORDER_SIZE];
    byte_l ope;

    pfr_file = fopen(puffer->path, "rb");
    if(!pfr_file){
        init_puffer(puffer);
        return;
    }
    for(int i = 0; ; i ++){
        if(i == ORDER_SIZE - 1){
            order[i] = 0x00;
            break;
        }
        read_byte(&order[i], pfr_file);
        if(order[i] == 0x00){
            break;
        }
    }

    for(int i = 0; ; i ++){
        switch(order[i]){
         // set page
        case 0x00:
            read_num(&(puffer->page_size), pfr_file);
            puffer->page = malloc(sizeof(set_page_s) * (puffer->page_size / 0x100'00));
            for(int i = 0; i < puffer->page_size; i ++){
                read_num(&(puffer->page[i].obj_size), pfr_file);
                puffer->page[i].obj = malloc(sizeof(obj_s) * (puffer->page[i].obj_size / 0x100'00));
                for(int j = 0; j < puffer->page[i].obj_size; j ++){
                    read_str(puffer->page[i].obj[j].name, pfr_file);
                    while(1){
                    read_byte(ope, pfr_file);
                        switch(ope){
                        case 0x00:
                            goto set_page_obj_line;
                        case 0x01:
                            read_color(&(puffer->page[i].obj[j].color), pfr_file);
                            break;
                        }
                    }
set_page_obj_line:
                    read_num(&(puffer->page[i].obj[j].line_size), pfr_file);
                    puffer->page[i].obj[j].line = malloc(sizeof(line_s) * (puffer->page[i].obj[j].line_size / 0x100'00));
                    for(int k = 0; k < puffer->page[i].obj[j].line_size; k ++){
                        read_byte(ope, pfr_file);
                        switch(ope){
                        case 0x00:
                            puffer->page[i].obj[j].line[k].type = HOR_LINE_TYPE;
                            read_num(&(puffer->page[i].obj[j].line[k].content.hor_line.a), pfr_file);
                            break;
                        case 0x01:
                            puffer->page[i].obj[j].line[k].type = VERT_LINE_TYPE;
                            read_num(&(puffer->page[i].obj[j].line[k].content.ver_line.a), pfr_file);
                            break;
                        case 0x02:
                            puffer->page[i].obj[j].line[k].type = LINEAR_FUNC_TYPE;
                            read_num(&(puffer->page[i].obj[j].line[k].content.linear_func.a), pfr_file);
                            read_num(&(puffer->page[i].obj[j].line[k].content.linear_func.b), pfr_file);
                            break;
                        }
                    }
                }
            }
            goto close_file;
         // set info
        case 0x01:
            while(1){
                read_byte(ope, pfr_file);
                switch(ope){
                case 0x00:
                    goto fin_set;
                case 0x01:
                    read_num(&(puffer->info.ver), pfr_file);
                    break;
                case 0x02:
                    read_str(&(puffer->info.author), pfr_file);
                    break;
                case 0x03:
                    read_str(&(puffer->info.title), pfr_file);
                    break;
                }
            }
            break;
        }
fin_set:
    }

close_file:
    fclose(pfr_file);
}
