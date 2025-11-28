#pragma once
#include <vector>

using namespace std;

class Wall {
public:
    vector <int> coord;

    Wall(int x1, int y1, int width, int height) {
        coord.push_back(x1);
        coord.push_back(y1);
        coord.push_back(width);
        coord.push_back(height);
    }
};

