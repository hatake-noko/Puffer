#include "terminal.h"

#include <stdlib.h>
#include <windows.h>

HWND terh;     // terminal handle
WNDCLASS terc; // terminal class

void create_terminal(void){
    terc.style = CS_HREDRAW | CS_VREDRAW;
    terc.lpfnWndProc = DefWindowProc;
    terc.cbClsExtra = winc.cbWndExtra = 0;
    terc.hInstance = hInstance;
    terc.hIcon = LoadIcon(NULL , IDI_APPLICATION);
    terc.hCursor = LoadCursor(NULL , IDC_ARROW);
    terc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    terc.lpszMenuName = NULL;
    terc.lpszClassName = TEXT("TERMINAL");

    if(!RegisterClass(&terc)){
        exit(EXIT_FAILURE);
    }

    terh = CreateWindow(
        TEXT("TERMINAL"),
        TEXT("TERMINAL_WND"),
        WS_OVERLAPPEDWINDOW | WS_VSCROLL,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        NULL, NULL, hInstance, NULL
	);

    if (terh == NULL){
        exit(EXIT_FAILURE);
    }

    ShowWindow(terh, SW_SHOW);

    return;
}
