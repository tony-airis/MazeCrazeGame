#pragma once
#include <vector>

using namespace std;

class WinArea {
public:
    int x1, y1, x2, y2;

    WinArea(int x1, int y1, int x2, int y2) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }

    bool CheckWin(int x, int y, int size) {
        bool flag = false;
        if ((x > x1) && (x + size < x2) && (y > y1) && (y + size < y2)) {
            flag = true;
        }
        return flag;
    }
    
};

