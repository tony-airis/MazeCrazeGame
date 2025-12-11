#pragma once
#include <vector>
#include "Wall.h"
#include "Player.h"
#include <string>

using namespace std;

class MazeField {
public:
    vector <Wall> walls;
    //Player player;

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
    walls.push_back(Wall(0, 0, 550, 15));
    walls.push_back(Wall(0, 0, 15, 180));
    walls.push_back(Wall(0, 170, 90, 15));
    walls.push_back(Wall(90, 90, 90, 15));
    walls.push_back(Wall(170, 90, 15, 180));
    walls.push_back(Wall(0, 260, 180, 15));
    walls.push_back(Wall(0, 260, 15, 550 - 260));
    walls.push_back(Wall(0, 540, 360, 15));
    walls.push_back(Wall(360, 360, 15, 190));
    walls.push_back(Wall(360, 360, 100, 15));
    walls.push_back(Wall(450, 180, 15, 190));
    walls.push_back(Wall(540, 0, 15, 550));
    walls.push_back(Wall(450, 450, 15, 90));
    walls.push_back(Wall(450, 540, 90, 15));
    walls.push_back(Wall(360, 90, 180, 15));
    walls.push_back(Wall(360, 90, 15, 90));
    walls.push_back(Wall(260, 0, 15, 370));
    walls.push_back(Wall(260, 260, 100, 15));
    walls.push_back(Wall(90, 360, 180, 15));
    walls.push_back(Wall(90, 360, 15, 100));
    walls.push_back(Wall(90, 460, 180, 15));
    }
    
    void MayMove(Player* player, string command) {
        int stepX = player->step, stepY = player->step;
        // проверка уменьшается ли координата на которую мы смещаемся (y перевернутый)
        if ((command == "up") || (command == "down")) {
            stepX = 0;
        } else {
            stepY = 0;
        }

        if ((command == "up") || (command == "left")) {
            stepX *= -1;
            stepY *= -1;
        }

        bool flag = true;
        for (int i = 0; i < walls.size(); i++) {
            // дальняя граница стены
            int x2 = walls[i].coord[0] + walls[i].coord[2];
            int y2 = walls[i].coord[1] + walls[i].coord[3];
            // дальняя граница игрока
            int x2p = player->x + player->size;
            int y2p = player->y + player->size;
            // проверка на столкновение со стенами
            if ( // проверка на левый верхний угол player`a
                ((player->x + stepX > walls[i].coord[0]) && (player->x + stepX < x2) &&
                (player->y + stepY > walls[i].coord[1]) && (player->y + stepY < y2)) || 
                // проверка на правый нижний угол player`a
                ((x2p + stepX > walls[i].coord[0]) && (x2p + stepX < x2) &&
                (y2p + stepY > walls[i].coord[1]) && (y2p + stepY < y2)) ||
                // проверка на правый верхний угол player`a
                ((x2p + stepX > walls[i].coord[0]) && (x2p + stepX < x2) &&
                (player->y + stepY > walls[i].coord[1]) && (player->y + stepY < y2)) ||
                // проверка на левый нижний угол player`a
                ((player->x + stepX > walls[i].coord[0]) && (player->x + stepX < x2) &&
                (y2p + stepY > walls[i].coord[1]) && (y2p + stepY < y2)) ||
                
                // проверка углов стен лабиринта
                // проверка на левый верхний угол стены лабиринта
                ((walls[i].coord[0] > player->x + stepX) && (walls[i].coord[0] < x2p + stepX) &&
                (walls[i].coord[1] > player->y + stepY) && (walls[i].coord[1] < y2p + stepY)) ||
                // проверка на правый нижний угол стены лабиринта
                ((x2 > player->x + stepX) && (x2 < x2p + stepX) &&
                (y2 > player->y + stepY) && (y2 < y2p + stepY)) ||
                // проверка на правый верхний угол стены лабиринта
                ((x2 > player->x + stepX) && (x2 < x2p + stepX) &&
                (walls[i].coord[1] > player->y + stepY) && (walls[i].coord[1] < y2p + stepY)) ||
                // проверка на левый нижний угол стены лабиринта
                ((walls[i].coord[0] > player->x + stepX) && (walls[i].coord[0] < x2p + stepX) &&
                (y2 > player->y + stepY) && (y2 < y2p + stepY))
                ) {
                flag = false;
            }
        }
        if (flag) {
            player->ChangeCoord(command);
        }
    }
};

