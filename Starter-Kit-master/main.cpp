// ************************************************************************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS                                                                   *
// Year: Trimester 1, 2022/23 (T2215)                                                                         *
// Lab: TT7L, TT6L                                                                                            *
// Names: Amgad Elrashid Gurashi Eltayeb | Balchi Maher M.  N. | Abdelrahman Mohamed Hassan Mohamed           *
// IDs: 1211307882 | 1221302826 | 1211305311                                                                  *
// Emails: 1211307882@student.mmu.edu.my | 1221302826@student.mmu.edu.my | 1211305311@student.mmu.edu.my      *
// Phones: 01160845164 | 017-3262018 | +60 17-298 4328                                                        *
// ************************************************************************************************************

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

void run()
{

    Intro intro;
    Alien alien;
     alien.randomAttri();
    // initialisers
    alien.alienPos(intro);
    intro.displayIntro();
    alien.charAttri(intro);
    // when the user change settings

    if (intro.getChanged() == true)
    {   
        pf::ClearScreen();
        intro.newBoard(intro, intro.getRows(), intro.getCol(), intro.getZombie(), intro.getChanged());
    }
    else
    {
        while (true)
        {
            alien.move(intro);
            pf::ClearScreen();

            intro.displayGame();
             alien.charAttri(intro);
            
        }
    }
}

int main()
{
   
   srand(time(NULL));
   
    run();
}
