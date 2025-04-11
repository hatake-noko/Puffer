#include"main.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include"puffer.h"
#include"token.h"

char msg[100][1024];
int msg_size;
char select[10][100];
int select_size;

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow){
    puffer_t puffer;
    WNDCLASS clean_wc;
    HWND clean_hw;
    MSG clean_m;

    clean_wc.style=CS_HREDRAW|CS_VREDRAW;
    clean_wc.lpfnWndProc=CleanMsg;
    clean_wc.cbClsExtra=0;
    clean_wc.cbWndExtra=0;
    clean_wc.hInstance=hInstance;
    clean_wc.hIcon=LoadIcon(NULL,IDI_APPLICATION);
    clean_wc.hCursor=LoadCursor(NULL,IDC_ARROW);
    clean_wc.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
    clean_wc.lpszMenuName=NULL;
    clean_wc.lpszClassName=TEXT("clean wc");

	if(!RegisterClass(&clean_wc)){
        return EXIT_FAILURE;
    }

    clean_hw=CreateWindow(TEXT("clean wc"),TEXT("clean"),WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL,hInstance,NULL);

    if(clean_hw==NULL){
        return EXIT_FAILURE;
    }

    ShowWindow(clean_hw,SW_SHOW);

    while(GetMessage(&clean_m,NULL,0,0)){
        DispatchMessage(&clean_m);
    }

    return clean_m.wParam;
}

LRESULT CALLBACK CleanMsg(HWND h,UINT m,WPARAM w,LPARAM l){
    HDC hdc;
    PAINTSTRUCT ps;

    switch(m){
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default:
        return DefWindowProc(h,m,w,l);
    }
    return 0;
}
