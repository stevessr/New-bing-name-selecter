#pragma once
unsigned int Movingspeed = 10;//��λ����
//std::string wordstosay = "i do not car";
std::string namefile = "����.txt";//��ȡ�ļ���
std::string settingfile = "setting.ini";//�����ļ��� to do
LPCSTR namefileW = "����.txt";//��ȡ�ļ���
LPCSTR WindowName = "������";
//LPCSTR Button2Name = "��������"; //new LPCSTR;
//strcpy(Button2Name , "������") ;

HWND hEdit;//�ı���1
HWND hEdit2;//�ı���2
HWND hButton;//��ť������ȡһ�ˡ�
HWND hButton2;//��ť����������ȡ��
bool scrolling = false;//�Ƿ����(ȫ�ֱ���)
HWND hButton3;//���¶�ȡ����
HWND hButton4;//�����ö�
bool IsTop = false;//�Ƿ��ö�
bool RandInit = false;//����������Ƿ��趨
HWND hButton5;//���������
HWND hButton6;//ѭ���ٶ�
HWND hButton7;//�Ƿ�����UTF8toGBK
bool UTF8toGBKS = false ;


int W_height = 150;//cy
int W_weight = 460;//cx

void duandian(){}
void WindowsInit( HWND hWnd ) {
int scrWidth, scrHeight;
RECT rect;
//�����Ļ�ߴ�
scrWidth = GetSystemMetrics(SM_CXSCREEN);
scrHeight = GetSystemMetrics(SM_CYSCREEN);
//ȡ�ô��ڳߴ�
GetWindowRect(hWnd, &rect);
//��������rect���ֵ
rect.left = (scrWidth - rect.right) / 1.8;
rect.top = (scrHeight - rect.bottom) / 1.7;
//�ƶ����ڵ�ָ����λ��
//SetWindowPos(hWnd, HWND_TOP, rect.left, rect.top, rect.right, rect.bottom, SWP_SHOWWINDOW);
SetWindowPos(hWnd, HWND_TOP, rect.left, rect.top, W_weight, W_height, SWP_SHOWWINDOW);
}


//???