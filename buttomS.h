#pragma once
void 按钮功能选择(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp){
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
        }
        else {
            W_top(hwnd);
        }
    }
    else if ((HWND)lp == hButton5) {
        RandomStartSet();
    }
    else if ((HWND)lp == hButton6) {
        ChangeSpeed();
    }
    else if ((HWND)lp == hButton7) {
        //if (UTF8toGBKS) {UTF8toGBKS=0;}else{UTF8toGBKS=1;}
        UTF8toGBKS = !UTF8toGBKS;
        hButton7Init();
    }
}

void 创建窗户(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    loadNames();
    WindowsInit(hwnd);
    hEdit = CreateWindow("EDIT", "初始状态", WS_VISIBLE | WS_CHILD | ES_READONLY, 10, 10, 200, 20, hwnd, NULL, NULL, NULL);
    hEdit2 = CreateWindow("EDIT", "初始状态", WS_VISIBLE | WS_CHILD | ES_READONLY, 10, 120, 200, 20, hwnd, NULL, NULL, NULL);
    hButton = CreateWindow("BUTTON", "抽取一人", WS_VISIBLE | WS_CHILD, 10, 40, 100, 30, hwnd, (HMENU)1, NULL, NULL);
    hButton2 = CreateWindow("BUTTON", "滚动名单", WS_VISIBLE | WS_CHILD, 120, 40, 100, 30, hwnd, (HMENU)2, NULL, NULL);
    hButton3 = CreateWindow("BUTTON", "重新加载名单", WS_VISIBLE | WS_CHILD, 230, 40, 100, 30, hwnd, (HMENU)3, NULL, NULL);
    hButton4 = CreateWindow("BUTTON", "未置顶", WS_VISIBLE | WS_CHILD, 340, 40, 100, 30, hwnd, (HMENU)4, NULL, NULL);
    hButton5 = CreateWindow("BUTTON", "重置随机数", WS_VISIBLE | WS_CHILD, 10, 80, 100, 30, hwnd, (HMENU)5, NULL, NULL);
    hButton6 = CreateWindow("BUTTON", "10ms", WS_VISIBLE | WS_CHILD, 120, 80, 100, 30, hwnd, (HMENU)6, NULL, NULL);
    hButton7 = CreateWindow("BUTTON", "无转换", WS_VISIBLE | WS_CHILD, 230, 80, 100, 30, hwnd, (HMENU)7, NULL, NULL); hButton7Init();
    //COMBOBOX,LISTBOX,SCROLLBAR,BUTTON
    //hButton6 = CreateWindow("BUTTON", "10ms", WS_VISIBLE | WS_CHILD,               120, 80, 100, 30, hwnd, (HMENU)6, NULL, NULL);
}