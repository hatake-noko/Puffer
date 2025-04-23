#include "token.h"

#include <stdlib.h>

#define is_whitespace(c) ((c) == ' ' || (c) == '\t' || (c) == '\r' || (c) == '\v')

int get_nth_token(char *token, char *base, int nth){
    int base_i = 0;
    int token_i = 0;
    for( ; ; base_i ++){
        if(is_whitespace(base[base_i])){
            ;
        }else if(base[base_i] == '\0'){
            return EXIT_FAILURE;
        }else{
            break;
        }
    }
    nth --;
    for( ; ; base_i ++){
        if(nth == 0){
fill_token:
            if(is_whitespace(base[base_i]) || base[base_i] == '\0'){
                return EXIT_SUCCESS;
            }else{
                token[token_i] = base[base_i];
                token_i ++;
            }
        }else if(base_i != 0 && is_whitespace(base[base_i - 1]) && !is_whitespace(base[base_i])){
            nth --;
            if(nth == 0){
                goto fill_token;
            }
        }else if(base[base_i] == '\0'){
            return EXIT_FAILURE;
        }
    }
}
