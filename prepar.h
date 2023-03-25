#pragma once
unsigned int Movingspeed = 10;//单位毫秒
//std::string wordstosay = "i do not car";
std::string namefile = "名单.txt";//读取文件名
std::string settingfile = "setting.ini";//设置文件名 to do
LPCSTR namefileW = "名单.txt";//读取文件名
LPCSTR WindowName = "点名器";
//LPCSTR Button2Name = "滚动名单"; //new LPCSTR;
//strcpy(Button2Name , "点名器") ;

HWND hEdit;
HWND hButton;//按钮：“抽取一人”
HWND hButton2;//按钮：”滚动抽取“
bool scrolling = false;//是否滚动(全局变量)
HWND hButton3;//重新读取名单
HWND hButton4;//窗口置顶
bool IsTop = false;//是否置顶

int W_height = 120;
int W_weight = 460;


//???