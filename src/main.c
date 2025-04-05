#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char cmd[100][1024];
int cmdSize = 0;
char select[10][100];
int selectSize = 0;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow){
    WNDCLASS terWC;
    HWND terHW;
    MSG terM;

    strcpy(select[selectSize], "puffer");
    selectSize ++;

    terWC.style = CS_HREDRAW | CS_VREDRAW;
    terWC.lpfnWndProc = TerminalWndProc;
    terWC.cbClsExtra = winc.cbWndExtra = 0;
    terWC.hInstance = hInstance;
    terWC.hIcon = LoadIcon(NULL , IDI_APPLICATION);
    terWC.hCursor = LoadCursor(NULL , IDC_ARROW);
    terWC.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    terWC.lpszMenuName = NULL;
    terWC.lpszClassName = TEXT("TERMINAL");
    if(!RegisterClass(&terWC)){
        MessageBox(NULL, "error", "cannot exe RegisterClass(&terWC)", MB_OK);
        exit(EXIT_FAILURE);
    }

    terHW = CreateWindow(
        TEXT("TERMINAL"),
        TEXT("TERMINAL HWND"),
        WS_OVERLAPPEDWINDOW | WS_VSCROLL,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        NULL, NULL, hInstance, NULL
    );
    if (!terHW){
        MessageBox(NULL, "error", "cannot exe CreateWindow(...)", MB_OK);
        exit(EXIT_FAILURE);
    }

    while(GetMessage(&terM, NULL, 0, 0)){
        DispatchMessage(&terM);
    }
    return terM.wParam;
}

LRESULT CALLBACK TerminalWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam){
    HDC hdc;
    PAINTSTRUCT ps;
    TEXTMETRIC tm;

    switch(msg){
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        GetTextMetrics(hdc, &tm);
        for(int i = 0; i < cmdSize; i ++){
            int x = 0;
            for(int j = 0; j < selectSize; j ++){
                for(int k = 0; k < strlen(select[j]); k ++){
                    x ++;
                    TextOut(hdc, 10 + tm.tmMaxCharWidth * x, 10 + tm.tmHeight * i, TEXT(select[j][k]), lstrlen(TEXT(select[j][k])));
                }
                for(int k = 0; k < 2; k ++){
                    x ++;
                    TextOut(hdc, 10 + tm.tmMaxCharWidth * x, 10 + tm.tmHeight * i, TEXT(": "[k]), lstrlen(TEXT(": "[k])));
                }
            }
            for(int j = 0; j < strlen(cmd[i]); j ++){
                x ++;
                TextOut(hdc, 10 + tm.tmMaxCharWidth * x, 10 + tm.tmHeight * i, TEXT(cmd[i][j]), lstrlen(TEXT(cmd[i][j])));
            }
        }
        EndPaint(hWnd, &ps);
        return 0;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}
