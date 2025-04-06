#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char cmd[100][1024];
int cmd_size;
char select[10][100];
int select_size;

int main(void){
    strcpy(cmd[0], "select puffer");
    cmd_size = 1;
    strcpy(select[0], "puffer");
    select_size = 1;

    printf("? select puffer");

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
                cmd[cmd_size][i] = '\0';
                break;
            }else{
                cmd[cmd_size][i] = (char)c;
            }
        }
        cmd_size ++;

        if(strcmp(cmd[cmd_size - 1], "unselect")){
            break;
        }else if(strcmp(cmd[cmd_size - 1], "version")){
            printf("compatible version: 1 0\n");
        }
    }

    return 0;
}
