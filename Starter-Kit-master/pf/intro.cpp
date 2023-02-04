#include "helper.h"
#include <iostream>
#include <climits>
#include <vector>
#include <iomanip>
#include <array>
#include <random>
#include <ctime>
#include <string>
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
    int zombie_life[5] = {100, 150, 200, 250, 300};
    int zombie_attack[4] = {5, 10, 15, 20};
    int zombie_range[3] = {1, 2, 3};
    int random_life, random_attack, random_range;
 
public:
    Alien(int life = 100, int attack = 0, int range = 0);
    void alienPos(Intro &intro);
    void move(Intro &intro);
    void alienDisplay(Intro &intro, Alien &alien);
    void charAttri();
    void randomAttri();
    int newAlienPosX(Intro &intro);
    int newAlienPosY(Intro &intro);
  
};

void Alien::charAttri()
{
    cout << "Alien   : Life " << life_ << " attack " << attack_ << endl;
    cout << "Zombie " << " : Life " << zombie_life[random_life] << " attack " << zombie_attack[random_attack] << " range : " << zombie_range[random_range] << endl;
}

void Alien::randomAttri()
{
    random_life = rand() % size(zombie_life);
    random_attack = rand() % size(zombie_attack);
    random_range = rand() % size(zombie_range);
}

int Alien::newAlienPosX(Intro &intro){
    return x_;
}
int Alien::newAlienPosY(Intro &intro){
    return y_;
}

void Alien::alienDisplay(Intro &intro, Alien &alien)
{
    intro.displayGame();
}

// when alien reaches boundary, when alien hits rock object, when he attack a zombie but the zombie lives the attack.

void Alien::move(Intro &intro)
{

    char empty = ' ';
    dir_ = ' ';
    dir_.clear();
    cout << "command> ";
    cin >> dir_;
    cout << endl;
    pf::ClearScreen();
    if (dir_ == "up")
    {
        while(true)
        if(newAlienPosY(intro) < intro.getRows()|| newAlienPosY(intro) < intro.getRows()){
            if(intro.isRock(x_ , y_ +1)){
                break;
            }
        intro.setObject(x_, y_, '.');
        y_++;
        intro.setObject(x_, y_, alien_);
        intro.displayGame();
        charAttri();
        pf::Pause();
        pf::ClearScreen();
        }
        else{
            break;
        }
    }

    if (dir_ == "down")
    {
         while(true)
        if(newAlienPosY(intro) > 1|| newAlienPosY(intro) > 1){
            if(intro.isRock(x_, y_ - 1)){
                break;
            }
        intro.setObject(x_, y_, '.');
        y_--;
        intro.setObject(x_, y_, alien_);
        intro.displayGame();
        charAttri();
        pf::Pause();
        pf::ClearScreen();
        }
        else{
            break;
        }
    }
    else if (dir_ == "left")
    {
        while(true)
        if(newAlienPosX(intro) > 1 || newAlienPosX(intro) > 1){
            if(intro.isRock(x_ -1, y_)){
                break;
            }
        intro.setObject(x_, y_, '.');
        x_--;
        intro.setObject(x_, y_, alien_);
        intro.displayGame();
        charAttri();
        pf::Pause();
        pf::ClearScreen();
        }
        else{
            break;
        }
    }
    else if (dir_ == "right")
    {
        while(true)
        if(newAlienPosX(intro) < intro.getCol() || newAlienPosX(intro) < intro.getCol()){
            if(intro.isRock(x_ + 1, y_)){
                break;
            }
        intro.setObject(x_, y_, '.');
        x_++;
        intro.setObject(x_, y_, alien_);
        intro.displayGame();
        charAttri();
        pf::Pause();
        pf::ClearScreen();
        }
        else{
            break;
        }
    }
    // intro.setObject(x_, y_, alien_);
    // if(dir_ == "up"){
    //     intro.setObject(x_, y_ - 1, empty);
    // }
    // else if(dir_ == "down"){
    //     intro.setObject(x_, y_ + 1, empty);
    // }
    // else if(dir_ == "left"){
    //     intro.setObject(x_ + 1, y_, empty);
    // }
    // else if(dir_ == "right"){
    //     intro.setObject(x_ - 1, y_, empty);
    // }
    // intro.setObject(x_, y_, alien_);
}

Alien::Alien(int life, int attack, int range)
{   life_ = life;
    attack_ = attack;
    range_ = range;
}

void Alien::alienPos(Intro &intro)
{
    alien_ = {'A'};
    y_ = (intro.getRows() + 1) / 2;
    x_ = (intro.getCol() + 1) / 2;
    zombie2_ = intro.getZombie();
    intro.setObject(x_, y_, alien_);
}

bool Intro::isZombie(int x, int y){
    return map_[rows_ - y][x - 1] == '1';
    return map_[rows_ - y][x - 1] == '2';
    return map_[rows_ - y][x - 1] == '3';
    return map_[rows_ - y][x - 1] == '4';
    return map_[rows_ - y][x - 1] == '5';
    return map_[rows_ - y][x - 1] == '6';
    return map_[rows_ - y][x - 1] == '7';
    return map_[rows_ - y][x - 1] == '8';
    return map_[rows_ - y][x - 1] == '9';
}

bool Intro::isArrowUp(int x, int y){
     return map_[rows_ - y][x - 1] == '^';
}
bool Intro::isArrowRight(int x, int y){
     return map_[rows_ - y][x - 1] == '>';
}
bool Intro::isArrowLeft(int x, int y){
     return map_[rows_ - y][x - 1] == '<';
}
bool Intro::isArrowDown(int x, int y){
     return map_[rows_ - y][x - 1] == 'v';
}

void Intro::newBoard(Intro &intro, int rows, int col, int zombie, bool changed)
{
    changed_ = true;
    Alien alien;
    int n = 0;
    // to make sure the objects in the map does not change every alien movement.
    while (n < 1)
    {
        mapinit(rows, col, zombie);
        alien.randomAttri();
        n++;
        break;
    }
    alien.alienPos(intro);
    while (true)
    {
        pf::ClearScreen();
        displayGame();
        alien.charAttri();
        alien.move(intro);
    }
}

bool Intro::isRock(int x, int y){
    return map_[rows_ - y][x-1] == 'r'; 
    }

bool Intro::getChanged() const
{
    return changed_;
}


int Intro::getZombie() const
{
    return zombie_;
}

int Intro::getCol() const
{
    return col_;
}

int Intro::getRows() const
{
    return rows_;
}

void Intro::setObject(int col, int rows, char ch)
{
    map_[rows_ - rows][col - 1] = ch;
}

void Intro::mapinit(int rows, int col, int zombie)
{
    rows_ = rows;
    col_ = col;

    char objects[] = {' ', ' ', ' ', ' ', ' ', ' ', 'p', 'h', 'h', 'r', '2', '^', '<', '>', 'v', 'r'};
    int noObjects = size(objects);
    // dynamic 2D array
    map_.resize(rows_); // create empty rows
    for (int i = 0; i < rows_; ++i)
    {
        map_[i].resize(col_); // resize each row
    }
    int noObj;
    // adding the objects into the map
    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < col_; j++)
        {
            noObj = rand() % noObjects; // generating random characters

            map_[i][j] = objects[noObj];
        }
    }
}

Intro::Intro(int rows, int col, int zombie, string choice, bool changed)
{
    rows_ = rows;
    col_ = col;
    zombie_ = zombie;
    choice_ = choice;
    changed_ = changed;
    mapinit(rows, col, zombie);
}

void Intro::displayGame()
{
    Alien alien;

    // to put the title in the middle part of the board.
    cout << setw((col_ + 2) / 2) << ". : Alien vs Zombie : ." << endl;
    for (int i = 0; i < rows_; i++)
    { // row is Y, col is X
        cout << "   ";
        for (int j = 0; j < col_; j++)
        {
            cout << "+---";
        }
        cout << "+" << endl;
        // row number diplaying
        cout << setw(2) << (i + 1);
        for (int j = 0; j < col_; j++)
        {
            cout << " | " << map_[i][j];
        }
        cout << " |" << endl;
    }
    cout << "   ";
    for (int j = 0; j < col_; j++)
    {
        cout << "+---";
    }
    cout << "+" << endl;

    cout << " ";
    // column numbering displays
    for (int j = 0; j < col_; j++)
    {
        int n = (j + 1) / 10;
        cout << " ";
        if (n == 0)
        {
            cout << " ";
        }
        else
        {
            cout << n;
        }
    }
    cout << endl;
    cout << " ";
    for (int j = 0; j < col_; j++)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl
         << endl;
}

void Intro::displayIntro()
{
    Intro intro;
    Alien alien;
    cout << "+--------------------------+" << endl;
    cout << "|  Default Game Settings   |" << endl;
    cout << "+--------------------------+" << endl;
    cout << endl;

    cout.width(5);
    cout << "Board Rows ";
    cout.width(6);
    cout << ":";
    cout.width(3);
    cout << rows_ << endl;

    cout.width(5);
    cout << "Board Columns ";
    cout.width(3);
    cout << ":";
    cout.width(3);
    cout << col_ << endl;

    cout.width(5);
    cout << "Zombie Count ";
    cout.width(4);
    cout << ":";
    cout.width(3);
    cout << zombie_ << endl;

    while (true)
    {

        cout << "Would you like to change the game settings (y/n)? => ";
        cin >> choice_;

        if (choice_ == "y" || choice_ == "Y")
        {
            choice_.clear();
            changeSettings();
        }

        else if ((choice_ != "y" && choice_ != "Y") && (choice_ != "n" && choice_ != "N"))
        {
            while (true)
            {
                choice_.clear();
                cout << "Invalid input, Please enter y/n => ";
                cin >> choice_;

                if (choice_ == "y" || choice_ == "Y")
                {
                    choice_.clear();
                    changeSettings();
                    break;
                }

                else if (choice_ == "n" || choice_ == "N")
                {
                    choice_.clear();
                    pf::ClearScreen();
                    displayGame();
                    break;
                }
            }
        }
        else if (choice_ == "n" || choice_ == "N")
        {
            choice_.clear();
            pf::ClearScreen();
            displayGame();
            break;
        }
        break;
    }
}

void Intro::changeSettings()
{
    Intro intro;
    Alien alien;
    pf::ClearScreen();

    if (choice_ == "n" || choice_ == "N")
    {
        return;
    }

    cout << "+--------------------------+" << endl;
    cout << "|  Board settings          |" << endl;
    cout << "+--------------------------+" << endl;
    cout << endl;

    cout << "Enter rows => ";
    while (!(cin >> rows_) || (rows_ % 2 == 0) || (rows_ <= 0)) // Even positive integer
    {
        cout << "Invalid input. Please enter an odd integer value => ";
        cin.clear();
        cin.ignore(INT_MAX, '\n'); // to clear input buffer 
    }

    cout << "Enter columns => ";
    while (!(cin >> col_) || (col_ % 2 == 0) || (col_ <= 0)) // Even positive integer
    {
        cout << "Invalid input. Please enter an odd integer value => ";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }

    cout << endl;
    cout << endl;

    cout << "Zombie Settings" << endl;
    cout << "-----------------" << endl;
    cout << "Enter the number of Zombies => ";
    cin >> zombie_;

    cout << "Settings updated" << endl;
    pf::Pause();
    pf::ClearScreen();
    changed_ = true;
    intro.newBoard(intro, rows_, col_, zombie_, changed_);
}
