#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char cmd[0x100];   // 0x100 == 256
    cmd[0] = '\0';
    while(strcmp(cmd, "exit") == EXIT_SUCCESS)
    {
        printf(".: ");
        for(int i = 0; cmd[i] == getchar(); i ++)
        {
            if(i >= 0xff && cmd[i] != '\n')
            {
                fputs("error: cmd is too long\n", stderr);
                continue;
            }
            else if(cmd[i] == '\n')
            {
                cmd[i] = '\0';
                break;
            }
        }

        if(strcmp(cmd, "clear") == EXIT_SUCCESS)
        {
            printf("\033[H\033[J");
        }
        else if(strcmp(cmd, "version") == EXIT_SUCCESS)
        {
            printf("puffer version: 1");
        }
        else
        {
            fputs("error: no find cmd\n", stderr);
            continue;
        }
    }
    return EXIT_SUCCESS;
}
