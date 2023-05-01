#include "perinlucde.h"

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_COMMAND:
            按钮功能选择(hwnd,msg,wp,lp);
            break;
        case WM_CREATE:
            创建窗户(hwnd, msg, wp, lp);
            break;
        case WM_TIMER:
            if (wp == 1 && scrolling) {
                string name = getRandomName();
                SetWindowText(hEdit, name.c_str());
            }
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd,msg ,wp ,lp);
    }
    return DefWindowProc(hwnd, msg, wp, lp) ;
}

int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hPrevInst ,LPSTR args,int ncmdshow){
    WNDCLASS wc = {0};
    wc.hbrBackground =(HBRUSH)COLOR_WINDOW ;
    wc.hCursor=LoadCursor(NULL,IDC_ARROW );
    wc.hInstance=hInst ;
    wc.lpszClassName="myWindowClass";
    wc.lpfnWndProc=WindowProcedure ;

if(!RegisterClass(&wc))
return -1;

CreateWindow("myWindowClass", WindowName , WS_OVERLAPPEDWINDOW | WS_VISIBLE,CW_USEDEFAULT,CW_USEDEFAULT ,W_weight,W_height,NULL,NULL,NULL,NULL);

MSG msg ={0};
while(GetMessage(&msg,NULL,NULL,NULL ))
{
TranslateMessage(&msg );
DispatchMessage(&msg );
}
return 0;
}



