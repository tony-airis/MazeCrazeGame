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
        walls.push_back(Wall(0, 0, 20, 1440));
        walls.push_back(Wall(0, 0, 1440, 100));
        walls.push_back(Wall(90, 90, 91, 100));
        walls.push_back(Wall(90, 90, 230, 100));
        walls.push_back(Wall(210, 90, 230, 100));
        //walls.push_back(Wall(0, 41, 250, 40));
        //walls.push_back(Wall(0, 41, 250, 40));
        //walls.push_back(Wall(0, 41, 250, 40));
        //walls.push_back(Wall(0, 41, 250, 40));
        //walls.push_back(Wall(0, 41, 250, 40));
        //walls.push_back(Wall(0, 41, 250, 40));
        //walls.push_back(Wall(0, 41, 250, 40));
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

