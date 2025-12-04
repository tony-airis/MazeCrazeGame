#pragma once
#include <string>
#include <utility>

using namespace std;

class Player {

public:
    int x;
    int y;
    int size = 60;
    // coord first - x, coord second - y
    //pair <int, int> coord;
    int step;

    Player() {
        //coord = make_pair(20, 40);
        step = 10;
    }
    

    /*pair <int, int> GetXY() {
        return coord;
    }*/

    void ChangeCoord(string command) {
        if (command == "up") {
            y -= step;
        }
        if (command == "down") {
            y += step;
        }
        if (command == "left") {
            x -= step;
        }
        if (command == "right") {
            x += step;
        }
    }
};


