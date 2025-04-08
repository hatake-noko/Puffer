#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "puffer.h"
#include "token.h"

char msg[100][1024];
int msg_size;
char select[10][100];
int select_size;

int main(void){
    puffer_t puffer;
    char token[256];

    strcpy(msg[0], "select puffer");
    msg_size = 1;
    strcpy(select[0], "puffer");
    select_size = 1;

    printf("? select puffer\n");

    while(1){
        for(int j = 0; j < select_size; j ++){
            printf("%s:", select[j]);
        }
        printf(" ? ");
        for(int i = 0; 1; i ++){
            int c = getchar();
            if(c == EOF){
                fputs("an error may have occurred while entering\n", stderr);
                return 1;
            }else if(c == '\n'){
                msg[msg_size][i] = '\0';
                break;
            }else{
                msg[msg_size][i] = (char)c;
            }
        }
        msg_size ++;

        get_token(msg[msg_size - 1], token, 256, 1);
        if(strcmp(token, "unselect") == 0){
            if(select_size <= 1){
                break;
            }else{
                select[select_size - 1][0] = '\0';
                select_size --;
            }
        }else if(strcmp(token, "version") == 0){
            printf("compatible version: 1\n");
        }else if(strcmp(token, "select") == 0){
            get_token(msg[msg_size - 1], token, 256, 2);
            switch(select_size){
            case 1:
                if(strcmp(token, "untitled") == 0){
                    init_puffer(&puffer);
                    strcpy(select[select_size], "untitled");
                    select_size ++;
                }
                break;
            case 2:
                if(strcmp(token, "info") == 0 || strcmp(token, "information") == 0){
                    strcpy(select[select_size], "info");
                    select_size ++;
                }
                break;
            }
        }else if(strcmp(token, "content") == 0 && select_size == 3 && strcmp(select[2], "info") == 0){
            print_info(&(puffer.info));
        }
    }

    return EXIT_SUCCESS;
}
