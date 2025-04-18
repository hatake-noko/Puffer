#include "main.h"

#include <stdio.h>
#include <string.h>

int main(void){
    char cmd[1024];
    char select[10][255];
    int select_size;

    strcpy(select[0], "Puffer");
    select_size = 1;

    while(1){
        for(int i = 0; i < select_size; i ++){
            printf("%s:", select[select_size]);
        }
        printf(" ? ");
        gets(cmd);

        switch(select_size){
        case 0:
            if(strcmp(cmd, "ver") == 0){
                puts("compatible version: 1");
            }else if(strcmp(cmd, "unselect") == 0){
                return 0;
            }else{
                goto no_find;
            }
            break;
        default:
        no_find:
            printf("error: no find the cmd `%s'", cmd);
            break;
        }
    }
}
