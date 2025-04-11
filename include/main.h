#ifndef PUFFER_MAIN_H
#define PUFFER_MAIN_H

#include <windows.h>

extern char cmd[1024][100];
extern int cmd_size;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);

#endif
