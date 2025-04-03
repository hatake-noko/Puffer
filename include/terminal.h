#ifndef PUFFER_TERMINAL_H
#define PUFFER_TERMINAL_H

#include <windows.h>

extern HWND terh;
extern WNDCLASS terc;

void create_terminal(void);
void ter_getcmd(void);

#endif
