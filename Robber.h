#pragma once
#include <string>
#include <utility>

using namespace std;

class Robber {

public:
    int x;
    int y;
    int size = 40;

    Robber(int x, int y) {
        this->x = x;
        this->y = y;
    }

    // проверка на то, что роббер схвачен
    bool checkGrab(Player* player) {
        if ((player->x <= x) && (player->x + player->size >= x + size) &&
            (player->y <= y) && (player->y + player->size >= y + size)) {
            return true;
        }
        return false;
    }
};