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
};


class Alien
{
private:
    int life_, attack_, range_, x_, y_, zombie2_;
    char alien_; // 'A'
    string dir_; // up, down, left, right
 
 
public:
   int zombie_life[5] = {100, 150, 200, 250, 300};
    int zombie_attack[4] = {5, 10, 15, 20};
    int zombie_range[3] = {1, 2, 3};
    int random_life, random_attack, random_range,* RandAttack, * Randlife, * Randrange;
    Alien(int life = 100, int attack = 0, int range = 0);
    void alienPos(Intro &intro);
    void move(Intro &intro);
    void alienDisplay(Intro &intro, Alien &alien);
    void charAttri();
    void randomAttri();

};