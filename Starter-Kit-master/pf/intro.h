#include <iostream>
#include <climits>
#include <vector>
#include <iomanip>
#include <array>
#include <random>
#include <ctime>
#include "helper.h"
#include <algorithm>
#include <cctype>

using namespace std;
class Intro
{
private:
    string choice_;
    int rows_, col_, zombie_;
    bool changed_;
    vector<vector<char>> map_;

public:
    int rows, col, zombie;
    Intro(int rows = 5, int col = 9, int zombie = 1, string choice = "", bool changed = false);
    void changeSettings();
    void displayIntro();
    void displayGame();
    void mapinit(int rows, int col, int zombie);
    void newBoard(Intro &intro, int rows, int col, int zombie, bool changed);
    void setObject(int col, int rows, char ch);
    int getRows() const;
    int getCol() const;
    int getZombie() const;
    bool getChanged() const;
    bool isRock(int x, int y);
    bool isZombie(int x, int y);
    char getObject(int x, int y);
    void removeTrail();
    bool isArrow(int x, int y);
    bool isHealth(int x, int y);
    bool isPod(int x, int y);
    void setZombie(int newZombie);
    bool isObject(int x, int y);
    void init();
    vector<vector<char>> getMap();
    void setMap(const vector<vector<char>> &newMap);
    void setRows(int row);
    void setCol(int col);
    void setZombies(int zombiess);
};

class Alien
{
private:
    int life_, attack_, range_, x_, y_, zombie2_;
    bool redir_;
    char alien_; // 'A'
    string dir_; // up, down, left, right and other commands
    int zombie_life[5] = {100, 150, 200, 250, 300};
    int zombie_attack[4] = {5, 10, 15, 20};
    int zombie_range[3] = {1, 2, 3};
    vector<int> random_life;
    vector<int> random_attack;
    vector<int> random_range;
    vector<char> zombies = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    vector<int> zombieCoordX;
    vector<int> zombieCoordY;
    int count = 0;

public:
    Alien(int life = 100, int attack = 0, int range = 0);
    void alienPos(Intro &intro);
    void move(Intro &intro);
    void alienDisplay(Intro &intro, Alien &alien);
    void charAttri(Intro &intro);
    void randomAttri(Intro &intro);
    int newAlienPosX(Intro &intro);
    int newAlienPosY(Intro &intro);
    void alienUp(Intro &intro);
    void alienLeft(Intro &intro);
    void alienRight(Intro &intro);
    void alienDown(Intro &intro);
    void moveLeft(Intro &intro);
    void moveRight(Intro &intro);
    void moveUp(Intro &intro);
    void moveDown(Intro &intro);
    void changeArrow(Intro &intro);
    void zombiePos(Intro &intro);
    void showHelp(Intro &intro);
    void zombieMove(Intro &intro);
    vector<int> getCoordX(Intro &intro);
    vector<int> getCoordY(Intro &intro);
    void closestZombie(Intro &intro);
    void hitZombie(Intro &intro, int x, int y);
    void deadZombie(Intro &intro);
    bool isMoveValid(int x, int y);
    void zombieAttack(Intro &intro, char zombie, int zombiex, int zombiey, int range, int attack);
    bool isWin(Intro &intro);
    bool isLose();
    void result(Intro &intro);
    void playAgain(Intro &intro);
    void resetGame(Intro &intro);
    void saveGame(Intro &intro);
    void loadGame(Intro &intro);
};
