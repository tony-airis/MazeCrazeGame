#pragma once
#include <string>
#include <utility>

using namespace std;

class Player {
public:
    // coord first - x, coord second - y
    pair <int, int> coord;
    int step;

    Player() {
        coord = make_pair(20, 40);
        step = 5;
    }

    pair <int, int> GetXY() {
        return coord;
    }

    void ChangeCoord(string command) {
        if (command == "up") {
            coord.second -= step;
        }
        if (command == "down") {
            coord.second += step;
        }
        if (command == "left") {
            coord.first -= step;
        }
        if (command == "right") {
            coord.first += step;
        }
    }
};


