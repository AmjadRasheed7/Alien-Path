#include <iostream>
#include <climits>
#include <vector>
#include <iomanip>
#include <array>
#include <random>
#include <ctime>
#include "helper.h"

using namespace std;
class Intro{
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
    bool isArrowUp(int x, int y);
    bool isArrowDown(int x, int y);
    bool isArrowLeft(int x, int y);
    bool isArrowRight(int x, int y);
};

class Alien
{
private:
    int life_, attack_, range_, x_, y_, zombie2_;
    char alien_; // 'A'
    string dir_; // up, down, left, right
    
    vector<int> zombie_life;
    vector<int> zombie_attack;
    vector<int> zombie_range;
    vector<int> tempL;
    vector<int> tempA;
    vector<int> tempR;


public:
    Alien(int life = 100, int attack = 0, int range = 0);
    void alienPos(Intro &intro);
    void move(Intro &intro);
    void alienDisplay(Intro &intro, Alien &alien);
    void charAttri();
    int getZombieLife();
    int getZombieRange();
    int getZombieAttack();
    int getLife();
    int getAttack();
    int newAlienPosX(Intro &into);
    int newAlienPosY(Intro &intro);
};
