#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char msg[100][1024];
int msg_size;
char select[10][100];
int select_size;

int main(void){
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

        if(strcmp(msg[msg_size - 1], "unselect") == 0){
            break;
        }else if(strcmp(msg[msg_size - 1], "version") == 0){
            printf("compatible version: 1 0\n");
        }
    }

    return EXIT_SUCCESS;
}
