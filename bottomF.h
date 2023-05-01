#pragma once
void loadNames() {
    ifstream file(namefile);
    string name;
    srand(time(0));
    while (getline(file, name)) {
        getline(file, name);
        //the old code is //name = UTF8ToGB(name.c_str()).c_str();    //name = name.c_str();
        if (UTF8toGBKS) { name = UTF8ToGB(name.c_str()).c_str(); }
        else { name = name.c_str(); }
        names.push_back(name);
        SetWindowText(hEdit, "文件初始化成功");
    }
}

void reloadnames(bool CG = false) {
    ifstream file(namefile);
    names.clear();
    string name;
    //int a = 10;
    while (getline(file, name)) {//while (a-- > 0) {
        getline(file, name);//name = UTF8ToGB(name.c_str()).c_str();
        if (UTF8toGBKS) { name = UTF8ToGB(name.c_str()).c_str(); }
        else { name = name.c_str(); }
        names.push_back(name);
    }
    //int WindowsX = GetSystemMetrics(SM_CXFULLSCREEN); //GetSystemMetrics(SM_CXSCREEN);//int WindowsY = GetSystemMetrics(SM_CYFULLSCREEN); //GetSystemMetrics(SM_CYSCREEN);//char WindowsXchar = char( WindowsX % 1000 ) ;
    //string rawTest =  "文件重新加载成功";//LPCTSTR Raw = rawTest.c_str() ;//duandian();//SetWindowText(hEdit, Raw );
    if (!CG) SetWindowText(hEdit, "文件重新加载成功");
}

void openFile() {
    ShellExecute(NULL, "open", namefileW, NULL, NULL, SW_SHOWNORMAL);
}

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

void RandomStartSet() {
    srand(time(0));
    SetWindowText(hEdit2, "随机数已重置");
}
string getRandomName() {
    if (names.size() == 0)names.push_back("没有人");
    //int index = rand() % names.size();
    return string(names[rand() % names.size()]);
}
void ChangeSpeed() {
    if (Movingspeed <= 1000 && Movingspeed >= 0)Movingspeed += 100; else Movingspeed = 10;

    string WordsTemp = "循环周期已改变为" + to_string(long(Movingspeed)) + "ms";string WordsTemp2 = to_string(long(Movingspeed)) + "ms";
    SetWindowText(hEdit2, WordsTemp.c_str());SetWindowText(hButton6, WordsTemp2.c_str());
    if (scrolling == true)stopScrolling(hButton2);
}

void hButton7Init() {
    if (!UTF8toGBKS) { SetWindowText(hButton7, "无转换"); }
    else { SetWindowText(hButton7, "UTF8toGBK"); }
    reloadnames(1);
}