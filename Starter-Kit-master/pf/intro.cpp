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
    char getObject(int x, int y);
    void removeTrail();
    bool isArrow(int x, int y);
    bool isHealth(int x, int y);
    bool isPod(int x, int y);
};

class Alien
{
private:
    int life_, attack_, range_, x_, y_, zombie2_, n = 0; 
    bool redir_;
    char alien_; // 'A'
    string dir_; // up, down, left, right
    int zombie_life[5] = {100, 150, 200, 250, 300};
    int zombie_attack[4] = {5, 10, 15, 20};
    int zombie_range[3] = {1, 2, 3};
    int random_life[9], random_attack[9], random_range[9];

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
};

void Alien::moveLeft(Intro &intro)
{
    while (true)
    {
        if (!(newAlienPosX(intro) > 1))
        {
            intro.displayGame();
            cout << "Alien hits the border." << endl;
            attack_ = 0;
            pf::Pause();
            pf::ClearScreen();
            break;
        }
        else if(intro.isHealth(x_ -1, y_)){
            life_ = life_ + 20;
            if(life_ > 100){
                life_ = 100;
            }
            intro.displayGame();
            cout << "Alien picks up a health pack" << endl;
            cout << "Alien life increased by 20." << endl;
            pf::Pause();
            pf::ClearScreen();
        }
        else if (intro.isRock(x_ - 1, y_))
        {
            intro.displayGame();
            cout << "Alien stumbles upon a rock." << endl;
            attack_ = 0;
            pf::Pause();
            pf::ClearScreen();
            break;
        }
        else if(intro.isPod(x_ - 1, y_)){
            // REDUCE ZOMBIE HEALTH.
        }
        else if (intro.getObject(x_ - 1, y_) == '>')
        {
            attack_ = attack_ + 20;
            intro.setObject(x_, y_, '.');
            x_--;
            intro.setObject(x_, y_, alien_);
            intro.displayGame();
            charAttri(intro);
            cout << "Alien picks up an arrow, and attack increased by 20." << endl;
            pf::Pause();
            pf::ClearScreen();
            moveRight(intro);
            break;
        }
        else if (intro.getObject(x_ - 1, y_) == '<')
        {
            attack_ = attack_ + 20;
            intro.displayGame();
            charAttri(intro);
            cout << "Alien picks up an arrow, and attack increased by 20." << endl;
            pf::Pause();
            pf::ClearScreen();
        }
        else if (intro.getObject(x_ - 1, y_) == '^')
        {
            attack_ = attack_ + 20;
            intro.setObject(x_, y_, '.');
            x_--;
            intro.setObject(x_, y_, alien_);
            intro.displayGame();
            charAttri(intro);
            cout << "Alien picks up an arrow, and attack increased by 20." << endl;
            pf::Pause();
            pf::ClearScreen();
            moveUp(intro);
            break;
        }
        else if (intro.getObject(x_ - 1, y_) == 'v')
        {
            attack_ = attack_ + 20;
            intro.setObject(x_, y_, '.');
            x_--;
            intro.setObject(x_, y_, alien_);
            intro.displayGame();
            charAttri(intro);
            cout << "Alien picks up an arrow, and attack increased by 20." << endl;
            pf::Pause();
            pf::ClearScreen();
            moveDown(intro);
            break;
        }
        intro.setObject(x_, y_, '.');
        x_--;
        intro.setObject(x_, y_, alien_);
        intro.displayGame();
        charAttri(intro);
        pf::Pause();
        pf::ClearScreen();
    }
}

void Alien::moveRight(Intro &intro)
{
    while (true)
    {
        if (!(newAlienPosX(intro) < intro.getCol()))
        {
            intro.displayGame();
            cout << "Alien hits the border." << endl;
            attack_ = 0;
            pf::Pause();
            pf::ClearScreen();
            break;
        }
        else if (intro.isRock(x_ + 1, y_))
        {
            intro.displayGame();
            cout << "Alien stumbles upon a rock." << endl;
            attack_ = 0;
            pf::Pause();
            pf::ClearScreen();
            break;
        }
        else if(intro.isHealth(x_ + 1, y_)){
            life_ = life_ + 20;
            if(life_ > 100){
                life_ = 100;
            }
            intro.displayGame();
            cout << "Alien picks up a health pack" << endl;
            cout << "Alien life increased by 20." << endl;
            pf::Pause();
            pf::ClearScreen();
        }
        else if(intro.isPod(x_ + 1, y_)){
            // REDUCE ZOMBIE HEALTH.
        }
        else if (intro.getObject(x_ + 1, y_) == '^')
        {
            attack_ = attack_ + 20;
            intro.setObject(x_, y_, '.');
            x_++;
            intro.setObject(x_, y_, alien_);
            intro.displayGame();
            charAttri(intro);
            cout << "Alien picks up an arrow, and attack increased by 20." << endl;
            pf::Pause();
            pf::ClearScreen();
            moveUp(intro);
            break;
        }
        else if (intro.getObject(x_ + 1, y_) == '>')
        {
            attack_ = attack_ + 20;
            intro.displayGame();
            charAttri(intro);
            cout << "Alien picks up an arrow, and attack increased by 20." << endl;
            pf::Pause();
            pf::ClearScreen();
        }
        else if (intro.getObject(x_ + 1, y_) == 'v')
        {
            attack_ = attack_ + 20;
            intro.setObject(x_, y_, '.');
            x_++;
            intro.setObject(x_, y_, alien_);
            intro.displayGame();
            charAttri(intro);
            cout << "Alien picks up an arrow, and attack increased by 20." << endl;
            pf::Pause();
            pf::ClearScreen();
            moveDown(intro);
            break;
        }
        else if (intro.getObject(x_ + 1, y_) == '<')
        {
            attack_ = attack_ + 20;
            intro.setObject(x_, y_, '.');
            x_++;
            intro.setObject(x_, y_, alien_);
            intro.displayGame();
            charAttri(intro);
            cout << "Alien picks up an arrow, and attack increased by 20." << endl;
            pf::Pause();
            pf::ClearScreen();
            moveLeft(intro);
            break;
        }
        intro.setObject(x_, y_, '.');
        x_++;
        intro.setObject(x_, y_, alien_);
        intro.displayGame();
        charAttri(intro);
        pf::Pause();
        pf::ClearScreen();
    }
}
void Alien::moveUp(Intro &intro)
{
    while (true)
    {
        if (!(newAlienPosY(intro) < intro.getRows()))
        {
            intro.displayGame();
            cout << "Alien hits the border." << endl;
            attack_ = 0;
            pf::Pause();
            pf::ClearScreen();
            break;
        }
        else if (intro.isRock(x_, y_ + 1))
        {
            intro.displayGame();
            cout << "Alien stumbles upon a rock." << endl;
            attack_ = 0;
            pf::Pause();
            pf::ClearScreen();
            break;
        }
        else if(intro.isPod(x_, y_ + 1)){
            // REDUCE ZOMBIE HEALTH.
        }
        else if(intro.isHealth(x_, y_ + 1)){
            life_ = life_ + 20;
            if(life_ > 100){
                life_ = 100;
            }
            intro.displayGame();
            cout << "Alien picks up a health pack" << endl;
            cout << "Alien life increased by 20." << endl;
            pf::Pause();
            pf::ClearScreen();
        }
        else if (intro.getObject(x_, y_ + 1) == 'v')
        {
            attack_ = attack_ + 20;
            intro.setObject(x_, y_, '.');
            y_++;
            intro.setObject(x_, y_, alien_);
            intro.displayGame();
            charAttri(intro);
            cout << "Alien picks up an arrow, and attack increased by 20." << endl;
            pf::Pause();
            pf::ClearScreen();
            moveDown(intro);
            break;
        }
        else if (intro.getObject(x_, y_ + 1) == '^')
        {
            attack_ = attack_ + 20;
            intro.displayGame();
            charAttri(intro);
            cout << "Alien picks up an arrow, and attack increased by 20." << endl;
            pf::Pause();
            pf::ClearScreen();

        }
        else if (intro.getObject(x_, y_ + 1) == '<')
        {
            attack_ = attack_ + 20;
            intro.setObject(x_, y_, '.');
            y_++;
            intro.setObject(x_, y_, alien_);
            intro.displayGame();
            charAttri(intro);
            cout << "Alien picks up an arrow, and attack increased by 20." << endl;
            pf::Pause();
            pf::ClearScreen();
            moveLeft(intro);
            break;
        }
        else if (intro.getObject(x_, y_ + 1) == '>')
        {
            attack_ = attack_ + 20;
            intro.setObject(x_, y_, '.');
            y_++;
            intro.setObject(x_, y_, alien_);
            intro.displayGame();
            charAttri(intro);
            cout << "Alien picks up an arrow, and attack increased by 20." << endl;
            pf::Pause();
            pf::ClearScreen();
            moveRight(intro);
            break;
        }

        intro.setObject(x_, y_, '.');
        y_++;
        intro.setObject(x_, y_, alien_);
        intro.displayGame();
        charAttri(intro);
        pf::Pause();
        pf::ClearScreen();
    }
}
void Alien::moveDown(Intro &intro)
{
    while (true)
    {
        if (!(newAlienPosY(intro) > 1))
        {
            intro.displayGame();
            cout << "Alien hits the border." << endl;
            attack_ = 0;
            pf::Pause();
            pf::ClearScreen();
            break;
        }
        else if (intro.isRock(x_, y_ - 1))
        {
            intro.displayGame();
            cout << "Alien stumbles upon a rock." << endl;
            attack_ = 0;
            pf::Pause();
            pf::ClearScreen();
            break;
        }
        else if(intro.isPod(x_, y_ - 1)){
            // REDUCE ZOMBIE HEALTH.
        }
        else if(intro.isHealth(x_, y_ - 1)){
            life_ = life_ + 20;
            if(life_ > 100){
                life_ = 100;
            }
            intro.displayGame();
            cout << "Alien picks up a health pack" << endl;
            cout << "Alien life increased by 20." << endl;
            pf::Pause();
            pf::ClearScreen();
        }
        else if (intro.getObject(x_, y_ - 1) == '>')
        {
            attack_ = attack_ + 20;
            intro.setObject(x_, y_, '.');
            y_--;
            intro.setObject(x_, y_, alien_);
            intro.displayGame();
            charAttri(intro);
            cout << "Alien picks up an arrow, and attack increased by 20." << endl;
            pf::Pause();
            pf::ClearScreen();
            moveRight(intro);
            break;
        }
        else if(intro.getObject(x_, y_ - 1) == 'v'){
            attack_ = attack_ + 20;
            intro.displayGame();
            charAttri(intro);
            cout << "Alien picks up an arrow, and attack increased by 20." << endl;
            pf::Pause();
            pf::ClearScreen();
        }
        else if (intro.getObject(x_, y_ - 1) == '<')
        {
            attack_ = attack_ + 20;
            intro.setObject(x_, y_, '.');
            y_--;
            intro.setObject(x_, y_, alien_);
            intro.displayGame();
            charAttri(intro);
            cout << "Alien picks up an arrow, and attack increased by 20." << endl;
            pf::Pause();
            pf::ClearScreen();
            moveLeft(intro);
            break;
        }
        else if (intro.getObject(x_, y_ - 1) == '^')
        {
            attack_ = attack_ + 20;
            intro.setObject(x_, y_, '.');
            y_--;
            intro.setObject(x_, y_, alien_);
            intro.displayGame();
            charAttri(intro);
            cout << "Alien picks up an arrow, and attack increased by 20." << endl;
            pf::Pause();
            pf::ClearScreen();
            moveUp(intro);
            break;
        }

        intro.setObject(x_, y_, '.');
        y_--;
        intro.setObject(x_, y_, alien_);
        intro.displayGame();
        charAttri(intro);
        pf::Pause();
        pf::ClearScreen();
    }
}

void Alien::charAttri(Intro &intro)
{
    cout << "Alien   : Life " << life_ << " attack " << attack_ << endl;
     for (int i = 1; i <= intro.getZombie(); i++)
    { 
    cout << "Zombie "<< i << " : Life " << random_life[i] << " attack " << random_attack[i] << " range : " << random_range[i] << endl;
  
  
   
    
}
}
void Alien::randomAttri(Intro &intro)
{  for (int i = 1; i <= intro.getZombie(); i++)
{   
    random_life[i] = zombie_life[rand() % size(zombie_life)];
    random_attack[i] = zombie_attack[rand() % size(zombie_attack)];
    random_range[i] = zombie_range[rand() % size(zombie_range)];

    
}
}
int Alien::newAlienPosX(Intro &intro)
{
    return x_;
}
int Alien::newAlienPosY(Intro &intro)
{
    return y_;
}

void Alien::alienDisplay(Intro &intro, Alien &alien)
{
    intro.displayGame();
}

void Alien::alienUp(Intro &intro)
{
    moveUp(intro);
}
void Alien::alienLeft(Intro &intro)
{
    moveLeft(intro);
}
void Alien::alienRight(Intro &intro)
{
    moveRight(intro);
}
void Alien::alienDown(Intro &intro)
{
    moveDown(intro);
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
        dir_.clear();
        alienUp(intro);
        intro.removeTrail();
    }

    else if (dir_ == "down")
    {
        dir_.clear();
        alienDown(intro);
        intro.removeTrail();
    }
    else if (dir_ == "left")
    {
        dir_.clear();
        alienLeft(intro);
        intro.removeTrail();
    }
    else if (dir_ == "right")
    {
        dir_.clear();
        alienRight(intro);
        intro.removeTrail();
    }
    else if (dir_ == "arrow")
    {
        dir_.clear();
        changeArrow(intro);
        pf::Pause();
    }
}

void Alien::changeArrow(Intro &intro)
{
    char object;
    int row;
    int col;
    intro.displayGame();
    cout << "Enter row => ";
    cin >> row;
    cout << endl;
    cout << "Enter column => ";
    cin >> col;
    cout << endl;
    cout << "Enter direction => ";
    cin >> dir_;
    cout << endl;
    // to find coordinates of the given values.
    object = intro.getObject(col, intro.getRows() - row + 1);
    if (dir_ == "left" && intro.isArrow(col, intro.getRows() - row + 1))
    {
        intro.setObject(col, intro.getRows() - row + 1, '<');
        cout << "Arrow " << object << " is now switched to <" << endl;
    }
    else if (dir_ == "right" && intro.isArrow(col, intro.getRows() - row + 1))
    {
        intro.setObject(col, intro.getRows() - row + 1, '>');
        cout << "Arrow " << object << " is now switched to >" << endl;
    }
    else if (dir_ == "up" && intro.isArrow(col, intro.getRows() - row + 1))
    {
        intro.setObject(col, intro.getRows() - row + 1, '^');
        cout << "Arrow " << object << " is now switched to ^" << endl;
    }
    else if (dir_ == "down" && intro.isArrow(col, intro.getRows() - row + 1))
    {
        intro.setObject(col, intro.getRows() - row + 1, 'v');
        cout << "Arrow " << object << " is now switched to v" << endl;
    }
    else
    {
        cout << "There are no arrows in that area." << endl;
    }
}

Alien::Alien(int life, int attack, int range)
{
    life_ = life;
    attack_ = attack;
    range_ = range;
}

void Alien::alienPos(Intro &intro)
{
    alien_ = {'A'};
    y_ = (intro.getRows() + 1) / 2;
    x_ = (intro.getCol() + 1) / 2;
    intro.setObject(x_, y_, alien_);
}

char Intro::getObject(int x, int y)
{
    return map_[rows_ - y][x - 1];
}

// this function requires modificiation, it doesn't work.
bool Intro::isZombie(int x, int y)
{
    return true;
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
        alien.randomAttri(intro);
        n++;
        break;
    }
    alien.alienPos(intro);
    while (true)
    {
        pf::ClearScreen();
        displayGame();
        alien.charAttri(intro);
        alien.move(intro);
    }
}

bool Intro::isHealth(int x, int y){
    return map_[rows_ - y][x - 1] == 'h';
}

bool Intro::isArrow(int x, int y)
{
    if (map_[rows_ - y][x - 1] == '>')
    {
        return true;
    }
    else if (map_[rows_ - y][x - 1] == '<')
    {
        return true;
    }
    else if (map_[rows_ - y][x - 1] == '^')
    {
        return true;
    }
    else if (map_[rows_ - y][x - 1] == 'v')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Intro::isRock(int x, int y)
{
    return map_[rows_ - y][x - 1] == 'r';
}

bool Intro::isPod(int x, int y){
    return map_[rows_ - y][x - 1] == 'p';
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

void Intro::removeTrail()
{
    Alien alien;
    char objects[] = {' ', ' ', ' ', ' ', 'p', 'h', 'h', 'r', '^', '<', '>', 'v'};
    int noObjects = size(objects);

    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < col_; j++)
        {
            int noObj = rand() % noObjects;
            if (map_[i][j] == '.')
            {
                setObject(j + 1, rows_ - i, objects[noObj]);
            }
        }
    }
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
    zombie_ = zombie;

    char objects[] = {' ', ' ', ' ', ' ', 'p', 'h', 'h', 'r', '^', '<', '>', 'v'};
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

    cout << "             ";
    // column numbering displays
    for (int j = 0; j < col_; j++)
    {
        int n = (j + 1) / 10;
        cout << " "; // between
        if (n == 0)
        {
            cout << setw(3);
        }
        else
        {
            cout << n << "  ";
        }
    }
    cout << endl;
    cout << "    ";
    for (int j = 0; j < col_; j++)
    {
        cout << " " << (j + 1) % 10 << "  ";
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
    cout << "Enter the number of zombies => ";
    while (!(cin >> zombie_) || (zombie_ <= 0))
    {
        cout << "Invalid input. Please enter an  integer value or greater than 0 => ";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }

    cout << "Settings updated" << endl;
    pf::Pause();
    pf::ClearScreen();
    changed_ = true;
    intro.newBoard(intro, rows_, col_, zombie_, changed_);
}
