// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TxxL
// Names: MEMBER_NAME_1 | MEMBER_NAME_2 | MEMBER_NAME_3
// IDs: MEMBER_ID_1 | MEMBER_ID_2 | MEMBER_ID_3
// Emails: MEMBER_EMAIL_1 | MEMBER_EMAIL_2 | MEMBER_EMAIL_3
// Phones: MEMBER_PHONE_1 | MEMBER_PHONE_2 | MEMBER_PHONE_3
// *********************************************************

// TODO: Fill in the missing information above and delete this line.

#include "pf/helper.h"
#include "pf/intro.h"
#include <iostream>
#include <climits>
#include <vector>
#include <iomanip>
#include <array>
#include <random>
#include <ctime>
using namespace std;

void run(){
    
    Intro intro;
    Alien alien;
    alien.alienPos(intro); 
    intro.displayIntro();
    if(intro.getChanged() == true){
        pf::ClearScreen();
        intro.newBoard(intro, intro.getRows(), intro.getCol(), intro.getZombie(), intro.getChanged());
    }
    else{
    while(true){
    cout << "test 2";
    alien.move(intro);
    pf::ClearScreen();
    intro.displayGame();
    }}
    
}

int main()
{   
    run();
   
}
