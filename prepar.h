#pragma once
unsigned int Movingspeed = 10;//单位毫秒
//std::string wordstosay = "i do not car";
std::string namefile = "名单.txt";//读取文件名
std::string settingfile = "setting.ini";//设置文件名 to do
LPCSTR namefileW = "名单.txt";//读取文件名
LPCSTR WindowName = "点名器";
//LPCSTR Button2Name = "滚动名单"; //new LPCSTR;
//strcpy(Button2Name , "点名器") ;

HWND hEdit;//文本框1
HWND hEdit2;//文本框2
HWND hButton;//按钮：“抽取一人”
HWND hButton2;//按钮：”滚动抽取“
bool scrolling = false;//是否滚动(全局变量)
HWND hButton3;//重新读取名单
HWND hButton4;//窗口置顶
bool IsTop = false;//是否置顶
bool RandInit = false;//随机数种子是否设定
HWND hButton5;//设置随机数
HWND hButton6;//循环速度
HWND hButton7;//是否启用UTF8toGBK
bool UTF8toGBKS = false ;


int W_height = 150;//cy
int W_weight = 460;//cx

void duandian(){}
void WindowsInit( HWND hWnd ) {
int scrWidth, scrHeight;
RECT rect;
//获得屏幕尺寸
scrWidth = GetSystemMetrics(SM_CXSCREEN);
scrHeight = GetSystemMetrics(SM_CYSCREEN);
//取得窗口尺寸
GetWindowRect(hWnd, &rect);
//重新设置rect里的值
rect.left = (scrWidth - rect.right) / 1.8;
rect.top = (scrHeight - rect.bottom) / 1.7;
//移动窗口到指定的位置
//SetWindowPos(hWnd, HWND_TOP, rect.left, rect.top, rect.right, rect.bottom, SWP_SHOWWINDOW);
SetWindowPos(hWnd, HWND_TOP, rect.left, rect.top, W_weight, W_height, SWP_SHOWWINDOW);
}


//???