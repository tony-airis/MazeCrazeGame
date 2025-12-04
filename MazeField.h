#pragma once
#include <vector>
#include "Wall.h"
#include "Player.h"
#include <string>

using namespace std;

class MazeField {
public:
    vector <Wall> walls;
    Player player;

    void CreateField() {
    /*walls.push_back(Wall(0, 0, 550, 10));
    walls.push_back(Wall(0, 0, 10, 180));
    walls.push_back(Wall(0, 180, 100, 10));
    walls.push_back(Wall(90, 90, 100, 10));
    walls.push_back(Wall(170, 90, 10, 180));
    walls.push_back(Wall(0, 260, 180, 10));
    walls.push_back(Wall(0, 260, 10, 550-260));
    walls.push_back(Wall(0, 540, 360, 10));
    walls.push_back(Wall(360, 360, 10, 190));
    walls.push_back(Wall(360, 360, 100, 10));
    walls.push_back(Wall(450, 180, 10, 190));
    walls.push_back(Wall(540, 0, 10, 550));
    walls.push_back(Wall(450, 450, 10, 100));
    walls.push_back(Wall(450, 540, 100, 10));
    walls.push_back(Wall(360, 90, 180, 10));
    walls.push_back(Wall(360, 90, 10, 100));
    walls.push_back(Wall(260, 0, 10, 370));
    walls.push_back(Wall(260, 260, 100, 10));
    walls.push_back(Wall(90, 360, 180, 10));
    walls.push_back(Wall(90, 360, 10, 100));
    walls.push_back(Wall(90, 460, 180, 10));*/
    walls.push_back(Wall(0, 0, 550, 10));
    walls.push_back(Wall(0, 0, 10, 180));
    walls.push_back(Wall(0, 170, 90, 10));
    walls.push_back(Wall(90, 90, 90, 10));
    walls.push_back(Wall(170, 90, 10, 180));
    walls.push_back(Wall(0, 260, 180, 10));
    walls.push_back(Wall(0, 260, 10, 550 - 260));
    walls.push_back(Wall(0, 540, 360, 10));
    walls.push_back(Wall(360, 360, 10, 190));
    walls.push_back(Wall(360, 360, 100, 10));
    walls.push_back(Wall(450, 180, 10, 190));
    walls.push_back(Wall(540, 0, 10, 550));
    walls.push_back(Wall(450, 450, 10, 90));
    walls.push_back(Wall(450, 540, 90, 10));
    walls.push_back(Wall(360, 90, 180, 10));
    walls.push_back(Wall(360, 90, 10, 90));
    walls.push_back(Wall(260, 0, 10, 370));
    walls.push_back(Wall(260, 260, 100, 10));
    walls.push_back(Wall(90, 360, 180, 10));
    walls.push_back(Wall(90, 360, 10, 100));
    walls.push_back(Wall(90, 460, 180, 10));
    }
    
    void MayMove(string command) {
        int step = player.step;
        int* coord = &player.coord.first;
        // смещение(переменная для выбора x или y в объекте wall)
        int offset = 0;
        // проверка уменьшается ли координата на которую мы смещаемся (y перевернутый)
        if ((command == "up") || (command == "left")) {
            step *= -1;
        }
        // проверяем идем мы по иксу или по игрику(какую пользовательскую координату надо менять)
        if ((command == "up") || (command == "down")) {
            // сохраняем по ссылке чтобы сразу менять переменную в объекте игрока
            coord = &player.coord.second;
            offset = 1;
        }

        bool flag = true;
        for (int i = 0; i < walls.size(); i++) {
            // см. коммент над offset
            if ((*coord + step < walls[i].coord[2 + offset]) && (*coord + step > walls[i].coord[0 + offset])) {
                flag = false;
            }
        }
        if (flag) {
            player.ChangeCoord(command);
        }
    }
};

