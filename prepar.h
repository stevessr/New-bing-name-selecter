#pragma once
unsigned int Movingspeed = 10;//��λ����
//std::string wordstosay = "i do not car";
std::string namefile = "����.txt";//��ȡ�ļ���
std::string settingfile = "setting.ini";//�����ļ��� to do
LPCSTR namefileW = "����.txt";//��ȡ�ļ���
LPCSTR WindowName = "������";
//LPCSTR Button2Name = "��������"; //new LPCSTR;
//strcpy(Button2Name , "������") ;

HWND hEdit;
HWND hButton;//��ť������ȡһ�ˡ�
HWND hButton2;//��ť����������ȡ��
bool scrolling = false;//�Ƿ����(ȫ�ֱ���)
HWND hButton3;//���¶�ȡ����
HWND hButton4;//�����ö�
bool IsTop = false;//�Ƿ��ö�

int W_height = 120;
int W_weight = 460;


//???