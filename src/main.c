#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char cmd[100][1024];
int cmdSize;
char select[10][100];
int selectSize;

int main(void){
    strcpy(cmd[0], "select puffer");
    cmdSize = 1;
    strcpy(select[0], "puffer");
    selectSize = 1;

    while(1){
        for(int i = 0; i < cmdSize; i ++){
            for(int j = 0; j < selectSize; j ++){
                printf("%s: ", select[j]);
            }
            printf("%s\n", cmd[i]);
        }
        scanf("%s", cmd[cmdSize]);
        cmdSize ++;

        if(strcmp(cmd[cmdSize - 1], "unselect")){
            break;
        }else if(strcmp(cmd[cmdSize - 1], "version")){
            printf("version: 1.0");
        }
    }
}
