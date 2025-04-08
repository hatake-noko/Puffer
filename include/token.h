#ifndef PUFFER_TOKEN_H
#define PUFFER_TOKEN_H

void change_esc(char *ret, const char *base);
void get_token(const char *base, char *token, int token_size, int nth);

#endif
