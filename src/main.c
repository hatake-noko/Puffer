#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "puffer.h"
#include "setting.h"
#include "token.h"

int main(void){
    puffer_s puffer;
    char cmd[1024];
    char select[10][255];
    int select_size;
    char token[1024];

    strcpy(select[0], "Puffer");
    select_size = 1;

    while(1){
        for(int i = 0; i < select_size; i ++){
            printf("%s:", select[i]);
        }
        printf(" ? ");
        gets(cmd);

        if(get_nth_token(token, cmd, 1) == EXIT_FAILURE){
            continue;
        }
        switch(select_size){
        case 1:
            if(strcmp(token, "ver") == 0){
                puts("compatible version: 1");
            }else if(strcmp(token, "unselect") == 0){
                return 0;
            }else if(strcmp(token, "select") == 0){
                if(get_nth_token(token, cmd, 2) == EXIT_SUCCESS){
                    strcpy(puffer.path, token);
                    for(int i = strlen(puffer.path) - 1; i >= 0; i --){
                        if(puffer.path[i] == PATH_DELIMITER){
                            for(int j = i + 1; j < strlen(puffer.path); j ++){
                                if(puffer.path[j] == '.'){
                                    break;
                                }
                                select[1][j - i - 1] = puffer.path[j];
                            }
                            goto fin_set_2nd_select;
                        }
                    }
fin_set_2nd_select:
                    read_puffer(&puffer);
                }else{
                    puffer.path[0] = '\0';
                    strcpy(select[1], "untitled");
                    init_puffer(&puffer);
                }
                select_size ++;
            }else{
                goto no_find;
            }
            break;
        case 2:
            if(strcmp(token, "unselect") == 0){
                free_puffer(&puffer);
                select_size --;
            }else if(strcmp(token, "select") == 0){
                if(get_nth_token(token, cmd, 2) == EXIT_FAILURE){
                    printf("error: no write set\n");
                    break;
                }else if(strcmp(token, "info") == 0 || strcmp(token, "information") == 0){
                    strcpy(select[2], "info");
                }else if(strcmp(token, "page") == 0){
                    strcpy(select[2], "page");
                }else{
                    printf("error: no find set\n");
                    break;
                }
                select_size ++;
            }else{
                goto no_find;
            }
            break;
        case 3:
            if(strcmp(token, "unselect") == 0){
                select_size --;
            }else if(strcmp(select[2], "info") == 0){
                if(strcmp(token, "ver") == 0 || strcmp(token, "version") == 0){
                    printf("version: %d", puffer.info.ver / 0x10000);
                }
            }else{
                goto no_find;
            }
            break;
        default:
no_find:
            printf("error: no find the cmd `%s\'\n", cmd);
            break;
        }
    }
}
