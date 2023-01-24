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
    vector<vector<char>> map_;

public:
    int rows, col, zombie;
    Intro(int rows = 5, int col = 9, int zombie = 1, string choice = "");
    void changeSettings();
    void displayIntro();
    void displayGame() const;
    void mapinit(int rows, int col, int zombie);
    void newBoard(Intro &intro, int rows, int col, int zombie);
    void setObject(int col, int rows, char ch);
    int getRows() const;
    int getCol() const;
};

class Alien
{
private:
    int life_, attack_, range_, x_, y_;
    char alien_; // 'A'

public:
    Alien(int life = 100, int attack = 0, int range = 1);
    void alienPos(Intro &intro);

};