#pragma once
#include <vector>
#include "Wall.h"
#include "Player.h"
#include "WinArea.h"
#include <string>

using namespace std;

class MazeField {
public:
    vector <Wall> walls;
    vector <WinArea> winareas;
    //Player player;

    void CreateField() {
        //область победы
        winareas.push_back(WinArea(360, 560, 460, 660));
        //стены
        walls.push_back(Wall(0, 0, 550, 15));
        walls.push_back(Wall(0, 0, 15, 185));
        walls.push_back(Wall(0, 170, 95, 15));
        walls.push_back(Wall(90, 90, 95, 15));
        walls.push_back(Wall(170, 90, 15, 185));
        walls.push_back(Wall(0, 260, 185, 15));
        walls.push_back(Wall(0, 260, 15, 555 - 260));
        walls.push_back(Wall(0, 540, 365, 15));
        walls.push_back(Wall(360, 360, 15, 195));
        walls.push_back(Wall(360, 360, 105, 15));
        walls.push_back(Wall(450, 180, 15, 195));
        walls.push_back(Wall(540, 0, 15, 555));
        walls.push_back(Wall(450, 450, 15, 95));
        walls.push_back(Wall(450, 540, 95, 15));
        walls.push_back(Wall(360, 90, 185, 15));
        walls.push_back(Wall(360, 90, 15, 95));
        walls.push_back(Wall(260, 0, 15, 375));
        walls.push_back(Wall(260, 260, 105, 15));
        walls.push_back(Wall(90, 360, 185, 15));
        walls.push_back(Wall(90, 360, 15, 105));
        walls.push_back(Wall(90, 460, 185, 15));
    }

    bool CheckWin(Player* player, int level) {
        bool flag = false;
        //проверяем находится ли игрок в области победы
        if (winareas[level - 1].CheckWin(player->x, player->y, player->size)) {
            flag = true;
        }
        return flag;
    }

    bool MayMove(Player* player, string command, int level) {
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
            return CheckWin(player, level);
        }
    }
    
};

