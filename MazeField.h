#pragma once
#include <vector>
#include "Wall.h"
#include "Player.h"
#include "WinArea.h"
#include "Robber.h"
#include <string>

using namespace std;

class MazeField {
public:
    vector <Wall> walls;
    vector <WinArea> winareas;
    vector <Robber> robbers;
    int level;
    //Player player;

    MazeField(int level) {
        this->level = level;
    }
    
    void CreateField() {
        //область победы
        winareas.push_back(WinArea(300, 560, 460, 660));
        winareas.push_back(WinArea(300, 560, 460, 660));
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

    void CreateLevel2() {
        // создаю 3-ех разбойников используя безмянный объект
        robbers.push_back(Robber(475, 27));
        robbers.push_back(Robber(478, 475));
        robbers.push_back(Robber(120, 393));
    }

    int WhichLevel() {
        return this->level;
    }
    void LevelUp() {
        this->level++;
        if (this->level == 2) {
            CreateLevel2();
        }
    }

    bool CheckWin(Player* player) {
        bool flag = false;
        
        //проверяем находится ли игрок в области победы для всех уровней 
        if (winareas[level - 1].CheckWin(player->x, player->y, player->size)) {
            flag = true;
        }

        // для второго и остальных уровней проверяем, что все воры схвачены
        if (level >= 2) {
            if (robbers.size() != 0) {
                flag = false;
            }
        }

        return flag;
    }

    bool MayMove(Player* player, string command) {
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

        // подвинулись мы или нет
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

        // если было движение 
        if (flag) {
            // изменяем координаты игрока 
            player->ChangeCoord(command);

            int grabI = -1;
            // проверяем, был ли схвачен кто-то из воров
            for (int i = 0; i < robbers.size(); i++) {
                // если вор пойман
                if (robbers[i].checkGrab(player)) {
                    // запоминаем пойманного
                    grabI = i;
                }
            }
            // удаляем пойманного 
            if (grabI != -1) {
                vector <Robber>::iterator iter = robbers.begin();
                robbers.erase(iter + grabI);
            }

            // проверяем наличие победы
            return CheckWin(player);
        }
        return false;
    }
    
};

