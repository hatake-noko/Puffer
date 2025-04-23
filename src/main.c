#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

int main(void){
    char cmd[1024];
    char select[10][255];
    int select_size;
    char token[1024];

    strcpy(select[0], "Puffer");
    select_size = 1;

    while(1){
        for(int i = 0; i < select_size; i ++){
            printf("%s:", select[select_size]);
        }
        printf(" ? ");
        gets(cmd);

        if(get_nth_token(token, cmd, 1) == EXIT_FAILURE){
            continue;
        }
        switch(select_size){
        case 0:
            if(strcmp(token, "ver") == 0){
                puts("compatible version: 1");
            }else if(strcmp(token, "unselect") == 0){
                return 0;
            }else{
                goto no_find;
            }
            break;
        default:
no_find:
            printf("error: no find the cmd `%s\'", cmd);
            break;
        }
    }
}
