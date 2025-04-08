#include "info.h"

#include <stdio.h>
#include <string.h>
#include "proc.h"

void init_info(info_t *info){
    init_proc(&(info->tag));
    info->version = 1;
    strcpy(info->title, "default title");
    strcpy(info->author, "default author");
    return;
}

void print_info(const info_t *info){
    printf("version: %d\n", info->version);
    printf("title: %s\n", info->title);
    printf("author: %s\n", info->author);
    return;
}
