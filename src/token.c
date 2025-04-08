#include "token.h"

#include <stdio.h>
#include <stdlib.h>

void get_token(const char *base, char *token, int token_size, int nth){
    if(token_size < 2){
        fputs("sys error: token size is too small\n", stderr);
        exit(EXIT_FAILURE);
    }
    int base_i;
    int token_start;
    int in_witespace = 1;
    for(base_i = 0; 1; base_i ++){
        if(base[base_i] == ' ' || base[base_i] == '\n' || base[base_i] == '\t' || base[base_i] == '\v' || base[base_i] == '\r'){
            if(in_witespace){
            }else{
                in_witespace = 1;
                nth --;
            }
        }else if(base[base_i] == '\0'){
            token[0] = '\0';
            return;
        }else{
            if(nth == 1){
                token[0] = base[base_i];
                token_start = base_i;
                break;
            }else if(in_witespace){
                in_witespace = 0;
            }
        }
    }
    for( ; 1; base_i ++){
        if(base_i - token_start >= token_size){
            fputs("sys error: no full size with token", stderr);
            exit(EXIT_FAILURE);
        }
        if(base[base_i] == ' ' || base[base_i] == '\n' || base[base_i] == '\t' || base[base_i] == '\v' || base[base_i] == '\r' || base[base_i] == '\0'){
            token[base_i - token_start] = '\0';
            break;
        }else{
            token[base_i - token_start] = base[base_i];
        }
    }
    return;
}
