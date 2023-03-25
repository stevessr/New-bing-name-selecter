#include "perinlucde.h";

void loadNames() {
    ifstream file(namefile);
    string name;
    //int a = 10;
    while (getline(file, name)) {
    //while (a-- > 0) {
        getline(file, name);
        name = UTF8ToGB(name.c_str()).c_str();
        names.push_back(name);
        SetWindowText(hEdit, "文件初始化成功");
    }
}

void reloadnames() {
    ifstream file(namefile);
    names.clear();
    string name;
    //int a = 10;
    while (getline(file, name)) {
        //while (a-- > 0) {
        getline(file, name);
        name = UTF8ToGB(name.c_str()).c_str();
        names.push_back(name);
    }
    SetWindowText(hEdit, "文件重新加载成功");
}

void openFile() {
    ShellExecute(NULL, "open", namefileW, NULL, NULL, SW_SHOWNORMAL);
}

/*void speakName(HWND hwnd) {
    char text[1024];
    GetWindowText(hEdit, text, 1024);

    CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
    ISpVoice* pVoice = NULL;

    if (FAILED(CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL,
        IID_ISpVoice, (void**)&pVoice))) {
        MessageBox(hwnd, "Error initializing text-to-speech engine.", "Error", MB_OK);
        return;
    }*/

void startScrolling(HWND hwnd) {
    scrolling = true;
    SetTimer(hwnd, 1, Movingspeed, NULL);
    SetWindowText(hButton2, "滚动中");
}
void stopScrolling(HWND hwnd) {
    scrolling = false;
    KillTimer(hwnd, 1);
    SetWindowText(hButton2, "滚动名单");
}

void W_not_top(HWND hwnd) {
    SetWindowPos(hwnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
    SetWindowText(hButton4, "未置顶");
    IsTop = false;
}
void W_top(HWND hwnd) {
    SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
    SetWindowText(hButton4, "已置顶");
    IsTop = true;
}

string getRandomName() {
    srand(time(0));
    if (names.size() == 0){
        names.push_back("没有人");
    }
    int index = rand() % names.size();
    return string(names[index]);
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_COMMAND:
            if ((HWND)lp == hButton) {
                string name = getRandomName();
                SetWindowText(hEdit, name.c_str());
            }
            else if ((HWND)lp == hButton2) {
                if (scrolling) {
                    stopScrolling(hwnd);
                }
                else {
                    startScrolling(hwnd);
                }
            }
            else if ((HWND)lp == hButton3) {
                reloadnames();
            }
            else if ((HWND)lp == hButton4) {
                if (IsTop) {
                    W_not_top(hwnd);
                }else {
                    W_top(hwnd);
                }
            }
            break;
        case WM_CREATE:
            loadNames();
            hEdit = CreateWindow("EDIT", "初始状态", WS_VISIBLE | WS_CHILD | ES_READONLY,       10, 10, 200, 20,hwnd, NULL, NULL, NULL);
            hButton = CreateWindow("BUTTON", "抽取一人", WS_VISIBLE | WS_CHILD,                 10, 40, 100, 30,hwnd,(HMENU)1,NULL,NULL);
            hButton2 = CreateWindow("BUTTON", "滚动名单"/*Button2Name*/, WS_VISIBLE | WS_CHILD, 120, 40, 100, 30, hwnd, (HMENU)2, NULL, NULL);
            hButton3 = CreateWindow("BUTTON", "重新加载名单", WS_VISIBLE | WS_CHILD,            230, 40, 100, 30, hwnd, (HMENU)3, NULL, NULL);
            hButton4 = CreateWindow("BUTTON", "未置顶", WS_VISIBLE | WS_CHILD,                  340, 40, 100, 30, hwnd, (HMENU)4, NULL, NULL);
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



