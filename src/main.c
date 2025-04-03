#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char cmd[1024][100];
int cmd_size = 0;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow){
    WNDCLASS ter_wc;
    HWND ter_hw;
    MSG ter_m;

    ter_wc.style = CS_HREDRAW | CS_VREDRAW;
    ter_wc.lpfnWndProc = TerminalWndProc;
    ter_wc.cbClsExtra = winc.cbWndExtra = 0;
    ter_wc.hInstance = hInstance;
    ter_wc.hIcon = LoadIcon(NULL , IDI_APPLICATION);
    ter_wc.hCursor = LoadCursor(NULL , IDC_ARROW);
    ter_wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    ter_wc.lpszMenuName = NULL;
    ter_wc.lpszClassName = TEXT("TERMINAL");
    if(!RegisterClass(&ter_wc)){
        MessageBox(NULL, "error", "cannot exe RegisterClass(&ter_wc)", MB_OK);
        exit(EXIT_FAILURE);
    }

    ter_hw = CreateWindow(
        TEXT("TERMINAL"),
        TEXT("TERMINAL HWND"),
        WS_OVERLAPPEDWINDOW | WS_VSCROLL,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        NULL, NULL, hInstance, NULL
    );
    if (!ter_hw){
        MessageBox(NULL, "error", "cannot exe CreateWindow(...)", MB_OK);
        exit(EXIT_FAILURE);
    }

    while(GetMessage(&ter_m, NULL, 0, 0)){
        DispatchMessage(&ter_m);
    }
    return ter_m.wParam;
}

LRESULT CALLBACK TerminalWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){
    switch(message){
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, message, wParam, lParam);
}
